## Aufgabe 6.1
Nennen Sie die Bedingungen für einen Ressourcen Deadlock!
> Wechselseitiger Ausschluss, Hold-and-wait-Bedingung, Ununterbrechbarkeit, Zyklisches Warten

## Aufgabe 6.2
Ein System hat sechs Bandlaufwerke, um die sich n Prozesse streiten. Jeder Prozess braucht bis zu zwei Laufwerke. Für welche n kann es zu keinem Deadlock kommen?
> Entweder gibt es nur maximal n=3 Prozesse, die nicht die gleichen Laufwerke verwenden (dann kann es zu keinem Deadlock kommen) oder die Prozesse müssen bspw unterbrochen werden können, sodass wenn sie die gleichen Laufwerke verwenden wollen, dass sie sich im Zugriff darauf abwechseln

## Aufgabe 6.3
Ein System hat vier Prozesse und fünf reservierbare Ressourcen. Die folgende Tabelle zeigt welche Ressourcen belegt sind und welche maximal benötigt werden.

|           | Belegt    | Maximal   | Need      | Verfügbar |
| --------- | --------- | --------- | --------- | --------- |
| Prozess A | 1 0 2 1 2 | 1 1 2 1 3 | 0 1 0 0 1 | 0 0 1 1 1 |
| Prozess B | 2 0 1 1 0 | 2 2 2 1 0 | 0 2 1 0 0 |           |
| Prozess C | 1 1 0 1 0 | 2 1 3 1 0 | 1 0 3 0 0 |           |
| Prozess D | 1 1 1 1 0 | 1 1 2 2 1 | 0 0 1 1 1 |           |
> Wenn x = 1 kann Prozess D ausgeführt werden.
> Führe D aus, gib D frei => Verfügbar (1 1 2 2 1)
> Führe A aus, gib A frei => Verfügbar (2 1 4 3 3)
> Führe C aus, gib C frei => Verfügbar (3 2 4 4 3)
> Führe B aus, gib B frei => Verfügbar (4 3 4 5 3)
