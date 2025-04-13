#include <Wire.h>
#include "I2Cdev.h"
#include <ODriveUART.h>
#include <PID_v1.h>
#include "MPU6050_6Axis_MotionApps20.h"

// Anlegen der UART-Schnittstellen zu OdriveMotoren
HardwareSerial& odriveSerial1 = Serial1; // Serial1 für ersten Motor
HardwareSerial& odriveSerial2 = Serial2; // Serial2 für zweiten Motor
ODriveUART odriveM1(odriveSerial1);
ODriveUART odriveM2(odriveSerial2);

// MPU Variablen
MPU6050 mpu;
bool dmpReady = false;  
byte mpuIntStatus, devStatus;   
unsigned int packetSize;        
unsigned int fifoCount;     
byte fifoBuffer[64]; 

// Winkelberechnung
Quaternion q;           // rotation and acceleration data 
VectorFloat gravity;    // gravity data of MPU
float ypr[3];           // yaw, pitch and roll data

// PID Variablen
double setpoint = 4.38;  // Sollwinkel: Trotz Kalibirierung bleibt ein Offset von ca. 4° erhalten
double PIDin, PIDout;
double Kp = 2.2; //2.2
double Ki = 4.2; //4.2
double Kd = 0.04; //0.04

// Anlegen der PID-Instanz
PID pid(&PIDin, &PIDout, &setpoint, Kp, Ki, Kd, DIRECT);

volatile bool mpuInterrupt = false;     
void dmpDataReady(){  
  mpuInterrupt = true;
}

void setup() {
    Serial.begin(250000);
    Wire.begin();
    mpu.initialize();
    devStatus = mpu.dmpInitialize();
    
    // Ermittelte Offsetwerte durch Kalibriermessung
    mpu.setXGyroOffset(100);
    mpu.setYGyroOffset(119);
    mpu.setZGyroOffset(92);
    mpu.setZAccelOffset(1644);

    // MPU Setup
    if (devStatus == 0) {
        Serial.println(F("MPU starting"));
        mpu.setDMPEnabled(true);
        attachInterrupt(0, dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();
        Serial.println(F("MPU ready"));
        dmpReady = true;
        packetSize = mpu.dmpGetFIFOPacketSize();

        // PID Setup
        pid.SetMode(AUTOMATIC);
        pid.SetSampleTime(5);
        pid.SetOutputLimits(-255, 255);
    } else {
        Serial.print("DMP failed ");
        Serial.print(devStatus); 
    }
  	
    // Odrive Setup
    odriveSerial1.begin(115200);
    odriveSerial2.begin(115200);
    initializeOdrive(odriveM1);
    initializeOdrive(odriveM2);
    
}

void initializeOdrive(ODriveUART& odrive) {
    while (odrive.getState() == AXIS_STATE_UNDEFINED) {
        delay(100);
    }
    while (odrive.getState() != AXIS_STATE_CLOSED_LOOP_CONTROL) {
        odrive.clearErrors();
        odrive.setState(AXIS_STATE_CLOSED_LOOP_CONTROL);
        delay(10);
    }
}

void loop() {
    if (!dmpReady) return; // Fehlerabfrage falls MPU nicht richtig initialisiert wurde
    
    mpuInterrupt = false;
    mpuIntStatus = mpu.getIntStatus();
    fifoCount = mpu.getFIFOCount();

    if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
        mpu.resetFIFO();
        Serial.println(F("FIFO overflow!"));
    } else if (mpuIntStatus & 0x02) {
        // MPU Buffer über dmp auslesen
        while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();
        mpu.getFIFOBytes(fifoBuffer, packetSize);
        fifoCount -= packetSize;
        mpu.dmpGetQuaternion(&q, fifoBuffer);
        mpu.dmpGetGravity(&gravity, &q);
        mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);

        // Regler anwenden
        PIDin = ypr[1] * 180 / M_PI;
        pid.Compute();
        
        // Motoren ansteuern
        odriveM1.setVelocity(PIDout);
        odriveM2.setVelocity(-PIDout);
        
        /*
        // Debug-Ausgabe
        Serial.print("Neigung: ");
        Serial.print(ypr[1] * 180 / M_PI);
        Serial.print(" | PIDout: ");
        Serial.println(PIDout);
        */
    }
}
