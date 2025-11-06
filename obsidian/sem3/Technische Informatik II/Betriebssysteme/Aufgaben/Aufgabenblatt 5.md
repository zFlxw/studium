## Aufgabe 5.1
Zu welchen Zeitpunkten wird das Scheduling durchgeführt?
> Scheduling wird bei der Erzeugung und Beendigung eines Prozesses oder beim Auftreten eines Interrupts (E-A Interrupt, zyklischer Interrupt/ Timerinterrupt) durchgeführt.
## Aufgabe 5.2
Kann durch das Analysieren von Quellcode ein Maß dafür angegeben werden, ob der
Prozess voraussichtlich rechenintensiv oder E/A-intensiv ist?
> Durch das Analysieren des Quellcodes könnte man bestimmen, ob der Prozess viele Ressourcen und/oder E-A-Operationen verwendet. Allerdings ist die Frage, ob sich das praktisch so sinnvoll umsetzen lässt.

Wie lässt sich das zur Laufzeit bestimmen?

## Aufgabe 5.3
Bestimmen Sie die CPU-Effizienz für die folgenden Fälle:
- In einem System läuft ein Prozess durchschnittlich eine Zeit T, bevor er durch Ein-/Ausgabe blockiert wird.
- Der Wechsel zwischen zwei Prozessen dauert die Zeit S
- Im Round-Robin-Scheduling wird nach einem Quantum Q der Prozess gewechselt

Untersuchen Sie die folgenden Fälle
- Q = ∞
	- Wenn Q unendlich ist, wird der Prozess erst nach T gewechselt (also wenn der Prozess fertig ist)
- T > Q
	- Wenn T > Q, dann braucht der Prozess mehrere Zyklen um abgeschlossen zu werden
- T > Q > S
	- Der Prozess braucht mehrere Zyklen und muss einen Teil seiner verfügbaren Zeit für den Wechsel aufopfern, wodurch er mehr Zyklen braucht
- Q = S
	- Der Prozess hat keine Zeit zu rechnen und die Zeit der Zyklen geht nur für den Prozesswechsel drauf
- Q ist ungefähr 0
	- der Prozess hat ebenfalls keine Zeit zu rechnen und die Prozesse wechseln nur hin und her

## Aufgabe 5.4
Fünf Stapelverarbeitungsjobs von A bis E kommen nahezu gleichzeitig in einem Rechenzentrum an. Ihre geschätzten Laufzeiten sind 10, 6, 2, 4 und 8 Minuten. Ihre Prioritäten sind 3, 5, 2, 1 bzw. 4. (Eine hohe Zahl bedeutet eine hohe Priorität.)

Bestimmen Sie den durchschnittlichen Prozessdurchlaufzeiten für die folgenden Schedulingstrategien:
1. Round Robin
	- A, B, C, D, E => A, B, D, E => A, B, E => A, E => A
	- Prozessdurchlaufzeit: Q
2. Prioritätsscheduling
	- B, E, A, C, D => E, A, C, D => A, C, D => C, D => D
	- durchschn. Prozessdurchlaufzeit: 6 Minuten
3. FCFS (First Come First Served in der Ankunftsreihenfolge A, B, C, D, E)
	- A, B, C, D, E => B, C, D, E => C, D, E => D, E => E
	- durchschn. Prozessdurchlaufzeit: 6 Minuten
4. STF (Shortest Job First)
	- C, D, B, E, A => D, B , E, A => B, E, A => E, A => A
	- durchschn. Prozessdurchlaufzeit: 6 Minuten

Für 1 gilt, dass das System ist multiprogrammiert ist und die CPU fair verteilt wird
Für 2-4 gilt, dass immer nur ein Job bis zum Ende läuft.

Alle Jobs sind rechenintensiv und die Zeiten für den Kontext-Switch sind vernachlässigbar.