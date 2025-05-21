# 🤖 Self-Balancing Robot

## Inhaltsverzeichnis
- [Projektbeschreibung](#projektbeschreibung)
- [Bilder und Videos](#bilder-und-videos)
- [Komponenten](#komponenten)
- [Schaltskizze](#schaltskizze)
- [Libraries](#libraries)
- [Durchgeführte Arbeiten](#durchgeführte-arbeiten)
- [Herausforderungen und Probleme](#herausforderungen-und-probleme)
- [Mögliche Erweiterungen](#mögliche-erweiterungen)
- [Fazit](#fazit)

---

## Projektbeschreibung  

Das Ziel dieses Projekts war es, einen selbstbalancierenden zweirädrigen Roboter als Differentialantrieb zu entwerfen, zu fertigen und zu programmieren. Dabei handelt es sich um ein mechatronisches System, das aufrecht bleibt, indem es kontinuierlich den Neigungswinkel misst und entsprechend gegensteuert – vergleichbar mit einem inversen Pendel.

### Motivation
Selbstbalancierende Roboter sind ein beliebtes Thema in der Robotik, da sie komplexe Regelungstechnik mit Sensorik, Echtzeitverarbeitung und Aktorik verbinden. Dieses Projekt diente dem praktischen Verständnis dieser Disziplinen und der Integration moderner Komponenten wie ODrive-Motorsteuerungen, MPU6050-Sensorik und Echtzeitregelung mit einem Teensy 4.0 Microcontroller.

### Anforderungen
- Modularer Aufbau um Erweiterungen leicht zu ermöglichen
- 10 kg Tragfähigkeit
- 2 m/s Geschwindigkeit
- Höhe ca. 75 cm (Tischhöhe)
- mindestens 2 Stunden Betriebszeit
- Ansteuerbarkeit über ROS2
- Budget von 1000 €
- Veröffentlichung und Dokumentation via Github

Folgende Bauteile wurden hierfür gestellt:
- Zwei Servomotoren, gesteuert über je ein ODrive S1 Board
- Zwei Bleisäureakkumulatoren

### Technische Umsetzung
Um die gegebenen Anforderungen zu erfüllen wurden [folgende Bauteile](https://github.com/Rayman0002/self-balancing-robot/tree/01634058a8744456b4b8e9eb85bf182ba5505895/Bestellliste) zugekauft:
- Eine MPU6050 (IMU) zur Winkelmessung, welche über I2C ausgelesen wird
- Ein Teensy 4.0 (TCU) als Hauptcontroller für das Regelungssystem (PID) der Traktion
- Ein Raspberry Pi 5 (VCU) für höhere Funktionen wie Netzwerkzugang oder ROS2-Integration
- DC/DC Wandler
- Not-Aus-Schalter

Das Chassis wurde aus Aluminiumprofilen gefertigt, um Robustheit und Modularität zu gewährleisten. Zusätzlich wurden alle spezifischen Halterungen und Aufnahmen im 3D-Druckverfahren gefertigt.

### Steuerung und Regelung
Ein geschlossener Regelkreis sorgt dafür, dass der Roboter sein Gleichgewicht selbstständig hält: Die IMU MPU6050 misst fortlaufend den aktuellen Neigungswinkel (Ist-Wert) und speichert die Messwerte in einem FIFO-Buffer, aus dem anschließend ein gleitender Mittelwert gebildet wird. Dadurch werden Störungen und Rauschen in den Sensordaten reduziert. Der so geglättete Winkelwert wird mit dem gewünschten Sollwert verglichen. Aus der dabei entstehenden Abweichung berechnet ein PID-Regler eine passende Stellgröße. Diese wird für die Drehzahlsteuerung der Motoren verwendet, wodurch die Antriebsmotoren die Neigung aktiv ausgleichen und den Roboter in aufrechter Position halten.

---

## Bilder und Videos
Sämtliche Bilder sind ebenso noch separat im Ordner [Images](https://github.com/Rayman0002/self-balancing-robot/tree/b4acf35143aba7584a2bec3d086b7ce9a561bfc9/Images) einsehbar und downloadbar.

### Bild des Roboters
<img src="https://github.com/Rayman0002/self-balancing-robot/blob/8eceb1a8b000328f6cab4dd2817c1807fa5aab82/Images/robot2.jpg" width="700">

### Video des Balanciervorgangs
<a href="https://youtube.com/shorts/DrgmVfjAZ9I?feature=share">
<img src="https://github.com/Rayman0002/self-balancing-robot/blob/15ef76217329cf2e615c9acc420301605097d795/Images/robot4.jpg" width="200" alt="Navigation in Simulation"></a>

---

## Komponenten  
Hier ein Überblick über die wichtigsten Bauteile des Roboters:

- **Teensy 4.0 (TCU)**  
  Dient als Hauptcontroller des Roboters. Mit seiner hohen Taktrate (600 MHz) ist er ideal für rechenintensive Aufgaben wie die PID-Regelung und die Verarbeitung der Sensordaten in Echtzeit.

- **MPU6050 (IMU)**  
  Dieses Modul ist günstig und weit verbreitet, es enthält ein 3-Achsen-Gyroskop und einen 3-Achsen-Beschleunigungssensor. Es liefert kontinuierlich Informationen über die Lage und Bewegung des Roboters und ist damit die zentrale Sensoreinheit.

- **Raspberry Pi 5 (VCU)**  
  Er ermöglicht höhere Rechenleistung für zukünftige Erweiterungen wie ROS2-Anbindung, Fernsteuerung oder autonome Navigation.

- **ODrive S1 Board**  
  Eine hochentwickelte Motorsteuerung für die verwendeten Gleichstrommotoren. Sie erlaubt präzise Regelung der Motorbewegung und Kommunikation über UART.

- **ODrive M8325s Motoren**  
  Diese Motoren liefern das nötige Drehmoment und die Geschwindigkeit, um den Roboter zu bewegen und gleichzeitig das Gleichgewicht zu halten.

- **Blei-Akkumulator LB12-12**  
  Ein robuster und zuverlässiger 12 V Bleiakku mit hoher Kapazität (12 Ah), der eine Laufzeit von über 2 Stunden ermöglicht und gleichzeitig als Gegengewicht im Chassis dient.

---

## Schaltskizze  

![Schaltskizze](https://github.com/Rayman0002/self-balancing-robot/blob/33c866d676f7b91e81d3d77172d776f20e32ad41/Images/shematic.png)

---

## Libraries  
Für die Realisierung der Softwarearchitektur kamen verschiedene spezialisierte Arduino- und C/C++-Bibliotheken zum Einsatz. Sie übernehmen wichtige Aufgaben wie die Kommunikation mit Sensoren, die Motorsteuerung und die Umsetzung der Regelalgorithmen:

- **Wire**  
  Die Standard-I2C-Bibliothek von Arduino, die für die Kommunikation mit dem MPU6050 verwendet wird. Sie ermöglicht den seriellen Datenaustausch zwischen dem Microcontroller und externen I2C-Geräten.

- **I2Cdev**  
  Eine benutzerfreundliche Schnittstellenbibliothek, entwickelt von Jeff Rowberg. Sie erleichtert das Auslesen von I2C-Sensoren wie dem MPU6050, indem sie die I2C-Kommunikation kapselt und abstrahiert.

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
  Der Rahmen des Roboters besteht aus stabilen Aluminiumprofilen, die nicht nur für eine solide Bauweise sorgen, sondern auch viel Spielraum für Anpassungen bieten. Diese modulare Struktur macht es einfach, Bauteile flexibel zu montieren und bei Bedarf umzubauen.
  Alle mechanischen Teile – von den Halterungen über die Elektronikaufnahmen bis hin zu den Rädern selbst – wurden eigenständig konstruiert und mittels 3D-Druck gefertigt. Dadurch konnte jedes Teil passgenau auf die Anforderungen abgestimmt werden.
  Die Räder sind eine vollständige Eigenkonstruktion. Zum einen aus kostentechnischen Gründen, zum anderen um die Verbindung zwischen Motoren und Rädern möglichst einfach zu gestalten. Hierdurch erspart man sich die Verwendung eines Getriebes.
Auf das 3D-gedruckte Rad wurde mit einem doppelseitigem Klebeband ein Gummistreifen aufgeklebt, welcher aufgrund des hohen Grips dem Schlupf der Räder entgegenwirkt. Des Weiteren wurde ein dünnes Netz integriert, um zu verhindern, dass auf dem Boden liegende Schrauben oder andere Kleinteile in den Motor gelangen.
  Zudem wurde ein digitaler Zwilling in CAD entworfen, um einen modellbasierten Regelungsentwurf zu ermöglichen.

- **Sensorintegration & Kalibrierung**  
  Anbindung und Kalibrierung des MPU6050-Sensors über I2C mittels des Teensy 4.0.
  Ein Temperaturdrift ist feststellbar, spielt bei den vorhandenen Temperaturänderungen im herkömlichen Betrieb jedoch keine Relevanz. Mit der Nutzung eines Heißluftföhns kann der Drift nachgewiesen werden.
  Dadurch, dass die IMU im aufrecht stehenden Zustand des Roboters keinen Winkel von exakt 0° liefert, ist eine Offsetkorrektur notwendig. Dieser Offset kann empirisch ermittelt werden.   

- **Regelung & Antrieb**  
  Nutzung eines PID-Reglers, der in Echtzeit auf Winkelabweichungen reagiert und die Motoren gezielt ansteuert, um den Roboter auszubalancieren. Dabei wurden verschiedene PID Regelparameter ausgetestet, um ein möglichst stabiles Systemverhalten zu realisieren. Die aktuellen Regelparameter sind so gewählt, dass sie einen ausgewogenen Kompromiss bilden. Einerseits sind die Werte groß genug, um schnell auf Abweichungen vom Sollwert zu reagieren. Andererseits sind sie klein genug, um ein aufschwingendes Verhalten zu vermeiden und einen stabilen, sicheren Zustand zu gewährleisten.

- **Motorsteuerung mit ODrive**  
  Konfiguration und serielle Ansteuerung des ODrive-Boards zur präzisen Steuerung beider Radmotoren.

- **Softwareentwicklung**  
  Modularer, effizienter [C-Code](https://github.com/Rayman0002/self-balancing-robot/tree/3e0792b9f9f8d5dc3f43347506e3ac82a5c26bf6/Code) für den Teensy-Microcontroller.

---

## Herausforderungen und Probleme  
Während der Entwicklung traten verschiedene kritische Systemzustände auf, die das Verhalten des Roboters massiv beeinflussten. Einige dieser „Sackgassen“ führten dazu, dass das System einen instabilen Zustand oder ein unzufriedenstellendes Ergebnis aufwies. 
Die zentralen Ursachen waren:

- **Maximale Drehzahl**  
  In der Motorkonfiguration kann die maximale Drehzahl der Motoren begrenzt werden. Dies entspricht einer Stellsignalbegrenzung, was zu einem instabilen Systemverhalten führt. 

- **Komplementärfilter als Fehlerquelle**  
  In einem früheren Entwicklungsstadium wurde ein Komplementärfilter zur Sensorfusion eingesetzt, um die Neigungsdaten aus Gyroskop und Beschleunigungssensor zu kombinieren. Leider führte dieser Filter – vermutlich durch falsche Parameter oder ungünstige Gewichtung (wobei sehr viele Parameter getestet wurden) – zu einer ungenauen oder verzögerten Winkelberechnung. Das Resultat war, dass der Roboter nicht balancierte oder sogar instabil reagierte. Erst nach Entfernung des Filters und direkter Nutzung der DMP-Daten des MPU6050 konnte das System zuverlässig auf Winkeländerungen reagieren.

- **Höhere Reglerzykluszeit**  
  Eine stabile Regelung des Roboters setzt eine konstante und ausreichend schnelle Regelzykluszeit voraus.
  Eine zu große Reglerzykluszeit hatte zur Folge, dass der Sollwert zu selten abgetastet wird und somit zu langsam auf eine Winkeländerung reagiert werden kann.
  In einem früheren Softwarestand wurde zyklisch der Zustand der Motoren überprüft und ein gegebenenfalls vorhandener Fehler quittiert. Dies führte dazu, dass die Reglerzykluszeit erhöht wurde.
  Bei einer zu geringen Reglerzykluszeit hat das System auch instabil reagiert. Hierbei konnte die Fehlerursache jedoch nicht ausfindig gemacht werden.
  Eine Zykluszeit von 5 ms hat sich als passend herausgestellt.

- **ODrive-Dokumentation**  
  Die offizielle Dokumentation war teilweise lückenhaft, widersprüchlich oder unvollständig, was den Einstieg deutlich erschwerte. Vieles musste durch Eigenversuche oder Community-Beiträge erarbeitet werden.

---

## Mögliche Erweiterungen
Im weiteren Projektverlauf bieten sich zahlreiche sinnvolle Erweiterungsmöglichkeiten, um die Funktionalität, Sicherheit und Autonomie des Roboters zu verbessern:

- **Integration eines Not-Aus-Schalters**  
  Für den sicheren Betrieb ist ein physischer Not-Aus-Schalter essenziell. Dieser soll die Stromzufuhr zu den Motoren sofort unterbrechen und im Fehlerfall Schäden oder Verletzungen verhindern. Der Not-Aus-Schalter muss hierzu über die Enable-Pins des S1-Boards angeschlossen werden. Das notwendige Vorgehen ist in der [ODrive Dokumentation](https://docs.odriverobotics.com/v/latest/manual/error-enable.html) beschrieben.

- **Einbindung von micro-ROS**  
  Durch die Anbindung des Systems an ROS2 mittels micro-ROS kann der Roboter in ein größeres Robotik-Ökosystem integriert werden. Hierfür muss der vorhandene Code des Teensy's in einen micro-ROS Rahmen integriert werden. Dies ermöglicht z. B. eine dynamische Regelparameteranpassung, Logging der Messwerte und Fernsteuerung des Roboters. 

- **Fernsteuerung**  
  Die Fernsteuerung erfolgt über ROS2, wobei ein Controller per Bluetooth oder USB mit dem Laptop verbunden ist. Dieser kommuniziert wiederum über WLAN mit dem auf dem Roboter verbauten Raspberry Pi.
  
- **Autonome Navigation & Kartographierung (SLAM)**  
  Eine langfristige Erweiterung ist die Ausstattung mit LiDAR oder Kamera zur Umgebungswahrnehmung. Mittels SLAM (Simultaneous Localization and Mapping) könnte der Roboter eigenständig Räume kartieren und navigieren.

- **Erweiterte Regelungsalgorithmen**  
  Anstelle des klassischen PID-Reglers könnte ein modellbasierter Zustandsregler eingesetzt werden. Solche Methoden erlauben eine präzisere Reaktion auf komplexe Dynamiken, insbesondere bei wechselnder Last oder höherer Geschwindigkeit. Denkbare Zustände wären die Geschwindigkeit, Position des Roboters ausgelesen über die Motoren sowie der Winkel und die Winkeländerungsrate ausgelesen über die IMU. 

- **Batteriespannungsüberwachung**  
  Für den sicheren Betrieb des Roboters ist es sinnvoll die Spannungen der Batterien zu überwachen, um so eine Tiefentladung der Batterien zu verhindern. Der sichere Betrieb ist somit gewährleistet, da die Motoren in keinen Fehlerzustand wegen Unterspannung gelangen.

---

## Fazit
Das Projekt hat gezeigt, dass sich ein selbstbalancierender Zweirad-Roboter mit Hilfe einer MPU6050-IMU, eines PID-Reglers und ODrive-Motorsteuerungen zuverlässig stabilisieren lässt. Zu Beginn verzögerte ein suboptimaler Ansatz mit einem Komplementärfilter die Stabilisierung erheblich und auch das Auffinden geeigneter PID-Parameter sowie die exakte Bestimmung des Sollwerts erwiesen sich als große Herausforderung. Erst nach intensiver Feinabstimmung der Reglerzykluszeit und Anpassung der Regelparameter konnte der Roboter dauerhaft balancieren. Innerhalb des vorgegebenen Budgets und mit modularem Aufbau wurden nahezu alle Anforderungen – von der Tragfähigkeit über die Fahrgeschwindigkeit bis zur Akkulaufzeit – erfüllt. Künftige Erweiterungen wie micro-ROS-Integration, autonome Navigation und erweiterte Regelungsalgorithmen bieten viel Potenzial, um den Roboter noch vielseitiger und robuster zu machen.
