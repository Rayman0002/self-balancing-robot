# 🤖 Self-Balancing Robot

## Inhaltsverzeichnis
- [Projektbeschreibung](#projektbeschreibung)
- [Bilder und Videos](#bilder-und-videos)
- [Bauteile](#bauteile)
- [Schaltskizze](#schaltskizze)
- [Libraries](#libraries)
- [Durchgeführte Arbeiten](#durchgeführte-arbeiten)
- [Dead-Locks](#dead-locks)
- [Was war nicht ideal](#was-war-nicht-ideal)
- [Erweiterungen](#erweiterungen)

---

## Projektbeschreibung  

Das Ziel dieses Projekts war es, einen selbstbalancierenden zweirädrigen Roboter mit Differentialantrieb zu entwerfen, zu fertigen und zu programmieren. Dabei handelt es sich um ein mechatronisches System, das aufrecht bleibt, indem es kontinuierlich den Winkel misst und entsprechend gegensteuert – vergleichbar mit einem inversen Pendel.

### Motivation
Selbstbalancierende Roboter sind ein beliebtes Thema in der Robotik, da sie komplexe Regelungstechnik mit Sensorik, Echtzeitverarbeitung und Aktorik verbinden. Dieses Projekt diente dem praktischen Verständnis dieser Disziplinen und der Integration moderner Komponenten wie ODrive-Motorsteuerungen, MPU6050-Sensorik und Echtzeitregelung mit einem Teensy 4.0 Microcontroller.

### Technische Umsetzung
Der Roboter ist ca. 75 cm hoch, trägt Lasten bis zu 10 kg und erreicht eine Akkulaufzeit von über 2 Stunden. 
Die Hauptkomponenten sind:
- Zwei Gleichstrommotoren, gesteuert über das ODrive S1 Board.
- Eine IMU (MPU6050) zur Winkelmessung, welche über I2C ausgelesen wird.
- Ein Teensy 4.0 als Hauptcontroller für das Regelungssystem (PID).
- Ein Raspberry Pi 5 für höhere Funktionen wie Netzwerkzugang oder ROS2-Integration.

Das Chassis wurde aus Aluminiumprofilen gefertigt, um Robustheit und Modularität zu gewährleisten. Zusätzlich wurden alle spezifischen Halterungen und Aufnahmen im 3D-Druckverfahren gefertigt.

### Steuerung und Regelung
Ein PID-Regler balanciert den Roboter anhand der Sensordaten. Die Software berücksichtigt die Trägheit, die Position und Geschwindigkeit der Motoren und die Neigung des Roboters.

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

## Durchgeführte Arbeiten

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

Während der Entwicklung traten verschiedene kritische Systemzustände auf, die das Verhalten des Roboters massiv beeinflussten. Einige dieser sogenannten „Dead-Locks“ führten dazu, dass das System manuell neu gestartet oder zurückgesetzt werden musste. Die zentralen Ursachen waren:

- **Motorenfehler zyklisch prüfen und quittieren**  
  Die ODrive-Motorcontroller reagieren empfindlich auf Zustände wie Überstrom, Encoderfehler oder Kommunikationsabbrüche. Wird ein solcher Fehler ausgelöst, verweigert das System jede weitere Motoraktivität – auch wenn der Fehlerzustand zwischenzeitlich behoben ist. Um diese Blockaden aufzulösen, musste im Code eine regelmäßige Abfrage und automatische Fehlerquittierung per UART-Protokoll implementiert werden.

- **Komplementärfilter als Fehlerquelle**  
  In einem früheren Entwicklungsstadium wurde ein Komplementärfilter zur Sensorfusion eingesetzt, um die Neigungsdaten aus Gyroskop und Beschleunigungssensor zu kombinieren. Leider führte dieser Filter – vermutlich durch falsche Parameter oder ungünstige Gewichtung – zu einer ungenauen oder verzögerten Lagedetektion. Das Resultat war, dass der Roboter nicht balancierte oder sogar bewusst instabil reagierte. Erst nach Entfernung des Filters und direkter Nutzung der DMP-Daten des MPU6050 konnte das System zuverlässig auf Lageänderungen reagieren.

- **Höhere Reglerzykluszeit**  
  Eine stabile Regelung des Roboters setzt eine konstante und ausreichend schnelle Regelzykluszeit voraus. Es zeigte sich, dass selbst geringe Verzögerungen – etwa durch serielle Kommunikation oder unnötige Berechnungen – zu einem trägen Verhalten führten. Das hatte zur Folge, dass der Roboter auf Neigungsänderungen zu spät oder gar nicht reagierte. Die Lösung bestand darin, den Regler präzise zeitgesteuert und ohne blockierende Funktionen zu betreiben.

---

## Was war nicht ideal

Trotz sorgfältiger Planung und Umsetzung gab es einen Aspekt, der sich als problematisch erwies:

- **ODrive-Dokumentation**  
  Die offizielle Dokumentation war teilweise lückenhaft, widersprüchlich oder unvollständig, was den Einstieg deutlich erschwerte. Vieles musste durch Eigenversuche oder Community-Beiträge erarbeitet werden.

---

## Erweiterungen

Im weiteren Projektverlauf bieten sich zahlreiche sinnvolle Erweiterungsmöglichkeiten, um die Funktionalität, Sicherheit und Autonomie des Roboters zu verbessern:

- **Integration eines Not-Aus-Schalters**  
  Für den sicheren Test- und Echtbetrieb ist ein physischer Not-Aus-Schalter essenziell. Dieser soll die Stromzufuhr zu den Motoren sofort unterbrechen und im Fehlerfall Schäden oder Verletzungen verhindern.

- **Einbindung von micro-ROS**  
  Durch die Anbindung des Systems an das Robot Operating System 2 mittels micro-ROS kann der Roboter in ein größeres Robotik-Ökosystem integriert werden. Dies ermöglicht z. B. eine standardisierte Zustandsübertragung, Fernwartung, Logging und die Nutzung bestehender ROS2-Tools.

- **Fernsteuerung per Webinterface oder App**  
  Mittels WLAN oder Bluetooth soll die manuelle Steuerung über ein mobiles Endgerät ermöglicht werden. Denkbar ist eine einfache Benutzeroberfläche zur Richtungssteuerung, Regelungseinstellungen oder Anzeige von Telemetriedaten.

- **Autonome Navigation & Kartographierung (SLAM)**  
  Eine langfristige Erweiterung ist die Ausstattung mit LiDAR oder Kamera zur Umgebungswahrnehmung. Mittels SLAM (Simultaneous Localization and Mapping) könnte der Roboter eigenständig Räume kartieren und navigieren.

- **Erweiterte Regelungsalgorithmen**  
  Anstelle des klassischen PID-Reglers könnte ein modellbasierter Zustandsregler eingesetzt werden. Solche Methoden erlauben eine präzisere Reaktion auf komplexe Dynamiken, insbesondere bei wechselnder Last oder höherer Geschwindigkeit.

---
