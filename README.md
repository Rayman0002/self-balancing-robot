# 🤖 Self-Balancing Robot

## 📑 Inhaltsverzeichnis
- [Projektbeschreibung](#-projektbeschreibung)
- [Libraries](#-libraries)
- [Bauteile](#-bauteile)
- [Schaltskizze](#-schaltskizze)
- [Erweiterungen](#-erweiterungen)
- [Dead-Locks](#-dead-locks)
- [Durchgeführt](#-durchgeführt)
- [Was war nicht ideal](#-was-war-nicht-ideal)
- [Bilder und Videos](#-bilder-und-videos)
- [Sonstiges](#-sonstiges)

---

## 📚 Projektbeschreibung
Ziel des Projekts war die Entwicklung und Realisierung eines selbstbalancierenden Roboters. Vorgegeben waren hierfür die zu verwendenden Motoren von ODrive sowie einige Anforderungen an das Design.  
Der Roboter ist ca. 75 cm hoch, weist eine Tragkraft von 10 kg auf und verfügt über eine Akkulaufzeit von über 2 Stunden.

Das Robotergestell wurde aus Aluminiumprofilen gefertigt, die zugeschnitten und individuell angepasst wurden. Sämtliche Halterungen für die Bauteile sowie die Radaufnahmen wurden mithilfe des 3D-Druckverfahrens hergestellt.

---

## 📦 Libraries
Verwendete Bibliotheken/Frameworks:
- `Wire`
- `I2Cdev`
- `ODriveUART`
- `PID_v1`
- `MPU6050_6Axis_MotionApps20`

---

## 🧩 Bauteile
Verwendete Hardware-Komponenten:
- Teensy 4.0
- MPU6050
- Raspberry Pi 5
- ODrive S1 Board
- ODrive M8325s Motoren
- Blei-Akkumulator LB12-12

---

## 🖇️ Schaltskizze
Hier eine beispielhafte Darstellung der Schaltung:
![Schaltskizze](pfad/zur/schaltskizze.png)

---

## ✨ Erweiterungen
Geplante Features oder mögliche Erweiterungen für zukünftige Versionen:
- Not-Aus-Schalter integrieren
- micro-ROS Implementierung
- Fernsteuerung realisieren
- Navigation und Kartografierung
- Zustandsregler implementieren

---

## 🧩 Dead-Locks
Kritische Punkte:
- Zyklisches Prüfen und Quittieren von Motorfehlern
- Verwendung eines Komplementärfilters zur Sensorfusion
- Optimierung der Reglerzykluszeit

---

## 🛠️ Durchgeführt
Erfolgreich umgesetzte Aufgaben:
- Mechanische Konstruktion und Fertigung
- Integration der ODrive-Motorsteuerung
- Entwicklung der Softwarelogik zur Balancierung

---

## ❗ Was war nicht ideal
- Die ODrive-Dokumentation war teilweise unvollständig und erschwerte die Implementierung.

---

## 🖼️ Bilder und Videos
Visuelle Eindrücke des Projekts:

### Beispielbild
![Screenshot](pfad/zum/screenshot.png)

### Beispielvideo
[![Video ansehen](https://img.youtube.com/vi/VIDEO_ID/0.jpg)](https://www.youtube.com/watch?v=VIDEO_ID)

---

## 📎 Sonstiges
(Optionale Inhalte wie Lizenzen, Danksagungen oder weiterführende Links.)

---
