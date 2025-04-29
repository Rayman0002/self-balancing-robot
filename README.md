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
**📚 Projektbeschreibung**

Ziel des Projekts war die Entwicklung und Realisierung eines selbstbalancierenden Roboters. Vorgegeben waren hierfür die zu verwendenden Motoren von ODrive sowie einige Anforderungen an das Design.  
Der Roboter ist ca. 75 cm hoch, weist eine Tragkraft von 10 kg auf und verfügt über eine Akkulaufzeit von über 2 Stunden.

Das Robotergestell wurde aus Aluminiumprofilen gefertigt, die zugeschnitten und individuell angepasst wurden. Sämtliche Halterungen für die Bauteile sowie die Radaufnahmen wurden mithilfe des 3D-Druckverfahrens hergestellt.

---

## Bilder und Videos  
**🖼️ Bilder und Videos**

### Bild des Roboters
![Screenshot](https://github.com/Rayman0002/self-balancing-robot/blob/6b631fcdf1065fbe495b8506c45cfa88e2e9ab59/Images/roboter.png)

### Beispielvideo
[![Video ansehen](https://img.youtube.com/vi/VIDEO_ID/0.jpg)](https://www.youtube.com/watch?v=VIDEO_ID)

---

## Bauteile  
**🧩 Bauteile**

Verwendete Hardware-Komponenten:
- Teensy 4.0
- MPU6050
- Raspberry Pi 5
- ODrive S1 Board
- ODrive M8325s Motoren
- Blei-Akkumulator LB12-12

---

## Schaltskizze  
**🖇️ Schaltskizze**

![Schaltskizze](https://github.com/Rayman0002/self-balancing-robot/blob/33c866d676f7b91e81d3d77172d776f20e32ad41/Images/shematic.png)

---

## Libraries  
**📦 Libraries**

Verwendete Bibliotheken/Frameworks:
- `Wire`
- `I2Cdev` (von Jeff Rowberg)
- `ODriveUART`
- `PID_v1`
- `MPU6050_6Axis_MotionApps20` (von Jeff Rowberg)

---

## Durchgeführt  
**🛠️ Durchgeführt**

Erfolgreich umgesetzte Aufgaben:
- Mechanische Konstruktion und Fertigung
- Integration der ODrive-Motorsteuerung
- Entwicklung der Softwarelogik zur Balancierung

---

## Dead-Locks  
**🧩 Dead-Locks**

Kritische Punkte:
- Zyklisches Prüfen und Quittieren von Motorfehlern
- Verwendung eines Komplementärfilters zur Sensorfusion
- Optimierung der Reglerzykluszeit

---

## Was war nicht ideal  
**❗ Was war nicht ideal**

- Die ODrive-Dokumentation war teilweise benutzerunfreundlich und erschwerte die Implementierung.

---

## Erweiterungen  
**✨ Erweiterungen**

Geplante Features oder mögliche Erweiterungen für zukünftige Versionen:
- Not-Aus-Schalter integrieren
- micro-ROS Implementierung
- Fernsteuerung realisieren
- Navigation und Kartografierung
- Zustandsregler implementieren

---
