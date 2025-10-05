## Checkliste
- [x] Historischer Überblick
- [x] Betriebssystemkonzepte

## Historischer Überblick
### Moore’sches Gesetz
> „Die Anzahl der Transistoren pro Chip verdoppelt sich ca. alle 2 Jahre“ - Gordon Moore, Mitbegründer von Intel (1986)

### Entwicklung
- Prozessoren werden immer
	- kleiner
	- leistungsfähiger
	- dichter
 - Anzahl an Prozessoren pro Mensch steigt massiv (viele Menschen besitzen mindestens 5 Geräte, in denen Prozessoren verbaut sind)
 - Paralellität auf Chips wird immer wichtiger
 - Leistungssteigerung ist wichtig, aber kommt auch mit Nachteilen (u.a. Batterielebensdauer wird kritisch)
- Hardware-Fortschritt = größere Komplexität auf der Platine (u. Software)
### Herausforderungen
- Wie orgranisiert man Komplexität in heterogenen Umgebungen?
- Wie können Anwendungen/ Computersysteme in Zukunft ihre Aufgaben erfüllen?
- Wie unterstützen Computer den Menschen/ das Geschäft?
- Welche neuen Herausforderungen/ Anwendungen kommen in der Zukunft?
### Lösung
- Rechnersysteme sollen Probleme lösen
- Rechnersysteme sind vielfältig & komplex

## Betriebssystemkonzepte
### Einfaches Schichtenmodell
- Das Betriebssystem soll dem Anwendungsentwickler ein „einfaches und klares Modell“ eines Computers zur Verfügung stellen
![[Pasted image 20251005193745.png]]
- Trennung zwischen **Benutzermodus** (user mode) und **Kernmodus** (kernel mode)

### Aufgaben des Betriebssystems
**1. Abstraktion der Hardware**
- Hardware beschränkt sich auf notwendige Funktionen, um günstig zu sein
	- Betriebssystem stellt Funktionen bereit, die Anwendungsprogramme nutzen können
- Trotz ähnlichem Aufbau unterscheiden sich Rechner im Detail stark
	→ Betriebssystem realisiert eine einheitliche Sicht für Anwendungen/ Anwendungsentwickler

**2. Verwaltung der Ressourcen**
- Anwendung braucht Ressourcen um ausgeführt zu werden
- Leistungsfähige Rechner laufen im Mehrprozess- / Mehrbenutzerbetrieb
- Betriebssystem verteilt die Ressourcen sinnvoll und sichert die Anwendungen und Benutzer gegenseitig ab
- **Multiplexing**:
	- Zeitliches Multiplexing („einer nach dem anderen“)
	- Räumliches Multiplexing („ein Teil für dich, ein Teil für mich“)

Betriebssystem ist also die **Mittelschicht** zwischen Anwendung und Hardware.
![[Pasted image 20251005195153.png]]
Darüber hinaus sorgt das Betriebssystem dafür, dass Anwendungen **nicht direkt** auf die Hardware zugreifen können.

## Geschichte der Betriebssysteme
### 1. Generation (bis 1945)
- Technologie: Elektronenröhren
- Manuelle Programmierung
	- Teilweise durch feste Verdrahtung
	- Einfache numerische Berechnungen möglich
### 2. Generation (1955 - 1965)
- Technologie: Transistoren (Großrechner)
- Trennung von Entwicklern, Operatoren, Wartungspersonal
- Lochkarten mit Programmcode (z.B. Assembler, Fortran)
- Betriebssystem
	- Startet Übersetzer und Programm
	- nimmt Eingabe entgegen
	- gibt Ausgabe auf Drucker aus
- Einführung von Jobs
	- Stapelverarbeitung (Batch)
### 3. Generation (1965 - 1980)
- Technologie: Integrierte Schaltungen (ICs)
	- Heute: Milliarden von Transistoren und anderen Bauteilen
- Einführung von Rechnerfamilien
	- Gleicher Befehlssatz
	- Unterschiedliche Leistung
	- Portabilität von Programmen möglich
	- Bsp. IBM System/360 mit Produkten 370, 380, 4300, …
- Betriebssystem soll unterschiede der Rechner/ Geräte abstrahieren
- Einführung des Mehrprogrammbetriebs
	- CPU wartet oft auf Ein-/Ausgabe (80 % - 90 % der Zeit)
	- Statt auf Ein-/Ausgabe zu warten, wird anderer Job aktiv
- Betriebssystem muss die Geräte verwalten
- Interaktive NUtzung der Rechner durch Timesharing
	- Terminals statt Lochkarten und Drucker
	- Mehrere Benutzer gleichzeitig
		→ Sicherheitsmechanismen notwendig
- Verbreitung von Minicomputern
	- DEC PDP-1 bis PDP-11
	- Ursprung von UNIX
### 4. Generation (1980 - heute)
- Technologie: Hochintegrierte Schaltkreise (Mikroprozessoren)
- Zurück zu Einbenutzersystemen (DOS, Windows, …)
- Von der Kommandozeile zu grafischen Benutzeroberflächen
- Zunehmende Vernetzung der Rechner
	- Client/ Server-Systeme: mehrere Benutzer
	- UNIX, Linux, Windows, …
- Verteilte Betriebssysteme (Cloud)
## Einfache Computer-Modelle
![[Pasted image 20251005201820.png]]
### Prozessor
- „Gehirn“ des Computers
	- Holt Befehle aus dem Speicher und führt sie aus
	- Abarbeitung von Programmen
- Unterschiedliche CPU-Typen haben unterschiedlichen Befehlssatz
	- Pentium-Programme laufen nicht auf SPARC-Maschinen
- Laden von Befehlen dauert länger als Ausführung
	- Optimierung durch Register (Speicherbereiche) innerhalb der CPU
	- Ganzzahl-, Gleitkomma-Register
		- Befehle um ein Wort von Speicher in Register zu schreiben
		- Befehle um ein Wort von Register in Speicher zu schreiben
		- Befehle kombinieren zwei Operanden aus Registern
- Spezialregister
	- Befehlszähler (Program Counter, PC)
		- Enthält Speicheradresse des nächsten Befehls
	- Kellerregister (Stack Pointer)
		- Zeigt auf das Ende des aktuellen Stacks
		- Hier werden Frames für jede angesprungene, aber nicht beendete Prozedur abgelegt
		- Eingabeparameter, lokale Variablen, …
	- Programmstatuswort (Program Status Word, PSW)
		- Enthält Status-Bits, CPU-Priorität, Modus (kernel mode / user mode)
		- Begrenzter Zugriff für Benutzermodus
			- Lesezugriff, beschränkter Schreibzugriff
		- Wichtig bei Systemaufrufen und Ein-/Ausgabe
- Verwaltung durch Multiplexing
	- Zeitliche Aufteilung der CPU Ressource
		- halte laufendes Programm an und starte anderes
	- Betriebssystem muss alle Register kennen
		- Speichern der Register und späteres Wiederherstellen
- Moderne Prozessoren
	- mehrere Befehle gleichzeitig ausführen
- Ausführungsmodi
	- Maßnahme, um den direkten Zugriff auf Systemressourcen durch Anwendungsprogramme zu unterbinden
		- Modus wird durch Bit im PSW gesetzt
	- Kernel Mode: Alle Befehle des Befehlssatzes können ausgeführt werden
	- User Mode: Eingeschränkter Zugriff auf Befehlssatz, Speicherzugriff nur über Betriebssystem
- Systemaufruf (kontrollierter Moduswechsel)
	- Aufruf im Kernel-Mode über das Betriebssystem
	- Betriebssystem muss aktiv werden
	- Andere Fälle, in denen Betriebssystem aktiv werden muss:
		- Interrupts (von Hardware erzeugt)
		- Exceptions (durch Programmfehler)
- 