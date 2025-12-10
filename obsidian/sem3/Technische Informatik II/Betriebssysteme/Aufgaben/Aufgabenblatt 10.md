## Aufgabe 10.1
> In der Vorlesung wurden Aspekte der Hardware diskutiert. Wie sind komplexe Gerät hardwareseitig im Allgemeinen aufgebaut?

Man braucht einen Controller, über den das Gerät angesprochen werden kann. Außerdem ist eine Hardware entweder blockorientiert (Daten werden in adressierbare Blöcke abgespeichert) oder zeichenorientiert (Gerät erzeugt oder verarbeitet Zeichenströme).

> Nennen Sie die vier Ein-/Ausgabeschichten um die Ein- und Ausgabe durch ein Betriebssystem zu realisieren!

Anwendung, Geräteunabhängige OS-Software, Gerätetreiber, Interrupts

> In welcher der vier Ein-/Ausgabeschichten werden die folgenden Aufgaben jeweils bearbeitet?
> 	a. Berechnung der Spur, des Sektors und des Kopfes beim Lesen von der Platte
> 	b. Schreiben von Kommandos in die Geräteregister
> 	c. Prüfung, ob ein Benutzer das Gerät verwenden darf
> 	d. Konvertierung von Binär-Integer-Zahlen nach ASCII zum Drucken

a: Controller
b: Gerätetreiber
c: Geräteunabhängige OS-Software
d: User I/O Software

## Aufgabe 10.2
> Ihr Computer kann ein Wort im Speicher in 10 ns lesen oder schreiben. Bei einem Interrupt legt dieser Computer alle 32 CPU Register, den Befehlszähler und das Programmstatuswort auf dem Stack ab. Wie viele Interrupts kann ihr Computer pro Sekunde verarbeiten?

Zeit: $34 \cdot 10 \cdot 10^{-9}s$
Zugriffe: $2\cdot 34$
pro Sekunde: $\dfrac{1s}{68 \cdot 10 \cdot 10^{-9}s}=1470588$

## Aufgabe 10.3
> Erklären Sie, wie ein Betriebssystem die Installation eines neuen Gerätes bewerkstelligen kann, ohne dass das gesamte Betriebssystem neu übersetzt werden muss.

Indem das Betriebssystem Treiber unterstützt, sodass lediglich eine neue Treiber Software entwickelt und dynamisch in das Betriebssystem geladen werden muss.

## Aufgabe 10.4
> Warum werden Dateien vor der Ausgabe an einen Drucker zunächst in einem Spooler-Ordner zwischengespeichert?

Ohne Spooler müsste das Programm, das den Druckvorgang gestartet hat, warten, bis der Vorgang beendet ist. Außerdem lässt sich durch den Spooler eine Warteschlange realisieren und falls ein Fehler beim Drucker auftritt, würden die Daten verloren gehen, wenn es den Spooler nicht gäbe. Zudem vermeidet man Deadlocks (Abhängigkeit von zwei Prozessen).