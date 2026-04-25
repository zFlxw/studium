## Generell
### Aufgaben eines BS
- Abstraktion der Hardware
- Verwaltung der Systemressourcen
### Abstrakte Konzepte eines BS
- Prozesse
- Adressraum
- Dateien

## Scheduling
### Kriterien
Benutzersicht:
- Minimierung der Durchlaufzeit
- Minimierung der Antwortzeit
- Einhalten von Terminen
- Vorhersehbarkeit
Systemsicht:
- Maximierung des Durchsatzes
- Optimierung der Prozessauslastung
- Balance (Gleichmäßige Auslastung aller Ressourcen)
- Fairness (Vergleichbare Prozesse werden gleich behandelt)
- Durchsetzung von Prioritäten (höhere Priorität wird bevorzugt)
### Strategien
Grundlegend:
- verdrängend: Aktueller Prozess wird unterbrochen und der neue Prozess wird sofort zwischengedrängt
- nicht-verdrängend: Erst wenn der aktuell laufende Prozess fertig ist, wird der neue Prozess gescheduled
Strategien:
- **First Come First Served** (FCFS) (nicht-verdrängend): Die Prozesse werden in der Reihenfolge, in der sie angekommen sind abgearbeitet. Das heißt, immer der Prozess, der am längsten wartet, wird ausgewählt. Erst, wenn der Prozess durchgelaufen ist, wird der neue gescheduled.
- **Shortest Job First** (SJF) (nicht-verdrängend): Der Prozess mit der kürzesten Laufzeit wird ausgeführt. Dafür müssen aber erstmal alle Prozesse vorliegen und analysiert werden
- **Shortest Remaining Time First** (SRTF) (verdrängend): Verdrängende Variante von SJF. Wir schauen immer, wenn ein neuer Prozess reinkommt, re-schedulen wir basierend darauf, welcher Prozess noch am wenigsten verbleibende Rechenzeit benötigt.
- **Round Robin** (RR): Arbeitet Prozesse der Reihe nach ab (FCFS), aber unterbricht nach einem bestimmten Zeitquantum $q$, sofern der Prozess nicht vorher selbst die CPU abgibt. Ob der Prozess verdrängend ist, hängt davon ab, wie wir ihn implementieren. Wenn wir sagen, dass pauschal bei jedem Scheduleraufruf (Interrupt) der Prozess gewechselt wird, ist er verdrängend. Wenn wir nur bei Timer Interrupts (und nicht bei bspw. I/O Interrupts) wechseln, ist er nicht verdrängend.
- **Prioritäten-basiertes Scheduling** (nicht-verdrängend): Der Prozess mit der höchsten Priorität wird abgearbeitet. Prozesse, innerhalb der gleichen Prioritätsklasse wird meist nach RR ausgewählt.
### Thread Scheduling
- Implementierung im Benutzermodus: geringere Kosten, aber Timer-Interrupts i. d. R. nicht möglich
- Implementierung im Kernmodus: Höhere Kosten (Umschalten von Threads $\widehat{=}$ Umschalten von Prozessen)

## Deadlocks
- Treten auf, wenn Prozess $A$ eine Ressource $R$ belegt und eine Ressource $S$ haben möchte, während Prozess $B$ die Ressource $S$ belegt und $R$ haben möchte
- Es gibt unterbrechbare und nicht unterbrechbare Ressourcen. Deadlocks treten immer bei nicht unterbrechbaren Ressourcen auf
- Verhungern: Prozess wartet (theoretisch) unendlich lang, aber kann von selbst enden. Beim Deadlock ist ein externes Eingreifen notwendig
### Bedingungen
- **Wechselseitiger Ausschluss** (Jede Ressource kann nur von einem Prozess genutzt werden)
- **Hold-and-Wait** Bedingung (Ein Prozess, der bereits eine Ressource besitzt, kann noch weitere Ressourcen anfordern)
- **Ununterbrechbarkeit** (Einem Prozess, der eine Ressource besitzt, kann diese nicht entzogen werden)
- **Zyklisches Warten** (Es gibt eine zyklische Kette von Prozessen, bei der jeder Prozess auf eine Ressource wartet, die vom nächsten Prozess in der Kette belegt ist)
- => alle vier Bedingungen sind notwendig, damit ein Deadlock entsteht
### Vermeidung von Deadlocks
- eine der obigen Bedingungen sicher vermeiden
- **Wechselseitiger Ausschluss**: Ressourcen nur dann an einzelne Prozesse zuteilen, wenn es unvermeidbar ist (z.B. Drucker an Drucker-Spooler)
- **Hold and Wait**: Vermeide Warten auf Ressourcen, alle benötigten Variablen werden zeitgleich angefordert
- **Ununterbrechbarkeit**: Quasi unmöglich
- **Zyklisches Warten**: Durchnummerieren der Ressourcen, Prozess darf nur Ressourcen mit größerer Nummer anfordern als bereits belegte Ressource
## Adressraum
- Gehört zu einem Prozess
