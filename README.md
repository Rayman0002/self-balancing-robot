# 🤖 Self-Balancing Robot

## Inhaltsverzeichnis
- [Projektbeschreibung](#projektbeschreibung)
- [Bilder und Videos](#bilder-und-videos)
- [Bauteile](#bauteile)
- [Schaltskizze](#schaltskizze)
- [Libraries](#libraries)
- [Durchgeführt](#durchgeführt)
- [Dead-Locks](#dead-locks)
- [Was war nicht ideal](#was-war-nicht-ideal)
- [Erweiterungen](#erweiterungen)

---

## Projektbeschreibung  

Das Ziel dieses Projekts war es, einen selbstbalancierenden zweirädrigen Roboter zu entwerfen, zu konstruieren und zu programmieren. Dabei handelt es sich um ein mechatronisches System, das aufrecht bleibt, indem es kontinuierlich seine Position und Lage im Raum erkennt und entsprechend gegensteuert – vergleichbar mit einem inversen Pendel.

### Motivation
Selbstbalancierende Roboter sind ein beliebtes Thema in der Robotik, da sie komplexe Regelungstechnik mit Sensorik, Echtzeitverarbeitung und Aktorik verbinden. Dieses Projekt diente dem praktischen Verständnis dieser Disziplinen und der Integration moderner Komponenten wie ODrive-Motorsteuerungen, MPU6050-Sensorik und Echtzeitregelung mit einem Teensy 4.0 Microcontroller.

### Technische Umsetzung
Der Roboter ist ca. 75 cm hoch, trägt Lasten bis zu 10 kg und erreicht eine Akkulaufzeit von über 2 Stunden. Die Hauptkomponenten sind:
- Zwei kraftvolle bürstenlose Gleichstrommotoren (BLDC), gesteuert über das ODrive S1 Board.
- Eine IMU (MPU6050) zur Lagemessung, welche über I2C ausgelesen wird.
- Ein Teensy 4.0 als Hauptcontroller für das Regelungssystem (PID).
- Ein Raspberry Pi 5 als optionaler Companion-Computer für höhere Funktionen wie Netzwerkzugang oder ROS-Integration.

Das Chassis wurde aus Aluminiumprofilen gefertigt, um Robustheit und Modularität zu gewährleisten. Zusätzlich wurden alle spezifischen Halterungen und Aufnahmen im 3D-Druckverfahren gefertigt.

### Steuerung und Regelung
Ein PID-Regler balanciert den Roboter anhand der Sensordaten. Die Software berücksichtigt die Trägheit, die Position und Geschwindigkeit der Motoren und die Neigung des Roboters.

### Besonderheiten
- Der Einsatz der ODrive-Plattform stellte hohe Anforderungen an das Timing und die Fehlerbehandlung im Echtzeitbetrieb.
- Die mechanische Konstruktion musste stabil und gleichzeitig leicht sein.
- Der Code wurde so gestaltet, dass spätere Erweiterungen wie ROS-Anbindung oder Fernsteuerung einfach möglich sind.

---

## Bilder und Videos
Sämtliche Bilder und Videos sind ebenso noch seperat im Ordner "Images" einsehbar und downloadbar.

### Bild des Roboters
![Screenshot](https://github.com/Rayman0002/self-balancing-robot/blob/6b631fcdf1065fbe495b8506c45cfa88e2e9ab59/Images/roboter.png)

### Video des Balanciervorgangs
[![Video ansehen](https://img.youtube.com/vi/VIDEO_ID/0.jpg)](https://www.youtube.com/watch?v=VIDEO_ID)

---

## Bauteile  

Für den Bau des selbstbalancierenden Roboters wurden sorgfältig ausgewählte Komponenten eingesetzt, um Stabilität, Rechenleistung und präzise Regelung zu gewährleisten. Hier ein Überblick über die wichtigsten Bauteile:

- **Teensy 4.0**  
  Dient als Hauptcontroller des Roboters. Mit seiner hohen Taktrate (600 MHz) ist er ideal für rechenintensive Aufgaben wie die PID-Regelung und die Verarbeitung der Sensordaten in Echtzeit.

- **MPU6050 (IMU)**  
  Dieses Modul enthält ein 3-Achsen-Gyroskop und einen 3-Achsen-Beschleunigungssensor. Es liefert kontinuierlich Informationen über die Lage und Bewegung des Roboters und ist damit die zentrale Komponente zur Balancierung.

- **Raspberry Pi 5**  
  Wird als optionaler Companion-Computer eingesetzt. Er ermöglicht höhere Rechenleistung für zukünftige Erweiterungen wie ROS-Anbindung, Fernsteuerung oder Bildverarbeitung.

- **ODrive S1 Board**  
  Eine hochentwickelte Motorsteuerung für bürstenlose Gleichstrommotoren (BLDC). Sie erlaubt präzise Regelung der Motorbewegung und Kommunikation über UART.

- **ODrive M8325s Motoren**  
  Diese BLDC-Motoren liefern das nötige Drehmoment und die Geschwindigkeit, um den Roboter zu bewegen und gleichzeitig das Gleichgewicht zu halten.

- **Blei-Akkumulator LB12-12**  
  Ein robuster und zuverlässiger 12V-Bleiakku mit hoher Kapazität (12 Ah), der eine Laufzeit von über 2 Stunden ermöglicht und gleichzeitig als Gegengewicht im Chassis dient.

---

## Schaltskizze  

![Schaltskizze](https://github.com/Rayman0002/self-balancing-robot/blob/33c866d676f7b91e81d3d77172d776f20e32ad41/Images/shematic.png)

---

## Libraries  

Für die Realisierung der Softwarearchitektur kamen verschiedene spezialisierte Arduino- und C++-Bibliotheken zum Einsatz. Sie übernehmen wichtige Aufgaben wie die Kommunikation mit Sensoren, die Motorsteuerung und die Umsetzung der Regelalgorithmen:

- **Wire**  
  Die Standard-I²C-Bibliothek von Arduino, die für die Kommunikation mit dem MPU6050 verwendet wird. Sie ermöglicht den seriellen Datenaustausch zwischen dem Microcontroller und externen I²C-Geräten.

- **I2Cdev**  
  Eine benutzerfreundliche Schnittstellenbibliothek, entwickelt von Jeff Rowberg. Sie erleichtert das Auslesen von I²C-Sensoren wie dem MPU6050, indem sie die I²C-Kommunikation kapselt und abstrahiert.

- **MPU6050_6Axis_MotionApps20**  
  Ebenfalls von Jeff Rowberg, diese Erweiterung nutzt die „DMP“ (Digital Motion Processor)-Funktionalität des MPU6050, um bereits vorverarbeitete Lagedaten (Yaw, Pitch, Roll) bereitzustellen. Dies entlastet den Mikrocontroller und erhöht die Genauigkeit der Bewegungsanalyse.

- **PID_v1**  
  Eine bekannte PID-Regler-Bibliothek, die es ermöglicht, stabile Regelkreise zu entwickeln. Sie verarbeitet die Sensordaten in Echtzeit und berechnet das erforderliche Stellmoment für die Motoren, um das Gleichgewicht des Roboters zu halten.

- **ODriveUART**  
  Eine Bibliothek zur seriellen Kommunikation mit dem ODrive S1 Board über UART. Sie bietet eine einfache Schnittstelle zur Steuerung der Motoren, zum Auslesen von Statuswerten und zum Handling von Fehlerzuständen.

---

## Durchgeführt

Im Rahmen des Projekts wurden mehrere komplexe Teilaufgaben erfolgreich umgesetzt – sowohl im mechanischen als auch im softwareseitigen Bereich:

- **Mechanische Konstruktion**  
  Planung, Zuschnitt und Aufbau eines stabilen Chassis aus Aluminiumprofilen. Dabei wurden alle tragenden Teile für Elektronik, Motoren und Batterie passgenau befestigt. Ergänzend kamen individuell konstruierte 3D-Druckteile zum Einsatz (z. B. Halterungen, Radaufnahmen).

- **Sensorintegration & Kalibrierung**  
  Anbindung und Kalibrierung des MPU6050-Sensors über I²C.

- **Regelung & Antrieb**  
  Entwicklung eines PID-Regelalgorithmus, der in Echtzeit auf Lageabweichungen reagiert und die BLDC-Motoren gezielt ansteuert, um den Roboter auszubalancieren.

- **Motorsteuerung mit ODrive**  
  Konfiguration und serielle Ansteuerung des ODrive-Boards zur präzisen Steuerung beider Radmotoren. Inklusive Fehlerbehandlung und Feedback-Abfrage über UART.

- **Softwareentwicklung**  
  Modularer, effizienter C++-Code für den Teensy-Microcontroller. Fokus auf gute Echtzeiteigenschaften, klare Trennung von Regelung, Sensorik und Kommunikation.

---

## Dead-Locks

Während der Entwicklung traten mehrere technische Herausforderungen auf, die besondere Aufmerksamkeit erforderten:

- **Fehlermeldungen des ODrive Boards**  
  Die Motorcontroller zeigten Fehlerzustände, die zyklisch abgefragt, analysiert und per Software quittiert werden mussten.

- **Regelzykluszeit & Latenz**  
  Die Balance hängt direkt von der Reaktionszeit des Systems ab. Eine zu lange oder schwankende Zykluszeit führte zu Instabilität. Daher musste die Software so optimiert werden, dass sie deterministisch und schnell genug reagiert.

- **Sensorrauschen & Lageregelung**  
  Rohdaten vom MPU6050 enthalten systembedingtes Rauschen.

---

## Was war nicht ideal

Trotz sorgfältiger Planung und Umsetzung gab es einen Aspekt, der sich als problematisch erwies:

- **ODrive-Dokumentation**  
  Die offizielle Dokumentation war teilweise lückenhaft, widersprüchlich oder unvollständig, was den Einstieg deutlich erschwerte. Vieles musste durch Eigenversuche oder Community-Beiträge erarbeitet werden.

---

## Erweiterungen

Um den Roboter weiterzuentwickeln und praxistauglicher zu machen, sind folgende Erweiterungen geplant oder denkbar:

- **Not-Aus-Schalter**  
  Ein physikalischer Sicherheitsschalter soll integriert werden, um den Roboter im Ernstfall sofort deaktivieren zu können.

- **micro-ROS Integration**  
  Anbindung an das Robot Operating System 2 (ROS 2) mithilfe von micro-ROS für vernetzte Robotik-Funktionen, z. B. Zustandstelemetrie oder Fernüberwachung.

- **Fernsteuerung**  
  Entwicklung einer Benutzeroberfläche zur manuellen Steuerung über WLAN/Bluetooth, z. B. per Smartphone-App.

- **Kartografierung und Navigation**  
  Aufbau eines SLAM-Systems zur Umgebungserfassung (z. B. mit LiDAR oder Kamera) und autonome Navigation durch bekannte Räume.

- **Zustandsregler statt PID**  
  Einsatz moderner Regelverfahren (z. B. LQR), die systemdynamische Modelle zur Optimierung verwenden und bei komplexeren Bewegungen stabiler arbeiten.


