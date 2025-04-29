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
Ein PID-Regler balanciert den Roboter anhand der Sensordaten. Die Software berücksichtigt die Trägheit, die Position und Geschwindigkeit der Motoren und die Neigung des Roboters. Die Sensorwerte werden mit einem Komplementärfilter geglättet, um stabile und verlässliche Steuerdaten zu erhalten.

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

Verwendete Hardware-Komponenten:
- Teensy 4.0
- MPU6050
- Raspberry Pi 5
- ODrive S1 Board
- ODrive M8325s Motoren
- Blei-Akkumulator LB12-12

---

## Schaltskizze  

![Schaltskizze](https://github.com/Rayman0002/self-balancing-robot/blob/33c866d676f7b91e81d3d77172d776f20e32ad41/Images/shematic.png)

---

## Libraries  

Verwendete Bibliotheken/Frameworks:
- `Wire`
- `I2Cdev` (von Jeff Rowberg)
- `ODriveUART`
- `PID_v1`
- `MPU6050_6Axis_MotionApps20` (von Jeff Rowberg)

---

## Durchgeführt  

Erfolgreich umgesetzte Aufgaben:
- Mechanische Konstruktion und Fertigung
- Integration der ODrive-Motorsteuerung
- Entwicklung der Softwarelogik zur Balancierung

---

## Dead-Locks  

Kritische Punkte:
- Zyklisches Prüfen und Quittieren von Motorfehlern
- Verwendung eines Komplementärfilters zur Sensorfusion
- Optimierung der Reglerzykluszeit

---

## Was war nicht ideal  

- Die ODrive-Dokumentation war teilweise benutzerunfreundlich und erschwerte die Implementierung.

---

## Erweiterungen  

Geplante Features oder mögliche Erweiterungen für zukünftige Versionen:
- Not-Aus-Schalter integrieren
- micro-ROS Implementierung
- Fernsteuerung realisieren
- Navigation und Kartografierung
- Zustandsregler implementieren

---
