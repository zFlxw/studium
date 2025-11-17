## Aufgabe 7.1
Die Verwaltung von freiem Speicher kann durch das Betriebssystem mit Bitmaps oder verketteten Listen realisiert werden. Für diese Datenstrukturen zur Verwaltung des freien Speichers wird auch Speicher benötigt.

Ihr System hat einen 128 MB großen Speicher. Als Vereinfachung nehmen Sie an das die Lücken bzw. die Segmente 64 kB groß sind und sich abwechseln. In der Liste müssen sie in den Knoten die Adresse mit 32 bit, die Länge mit 16 bit und den Zeiger auf den nächsten Knoten mit 16 bit speichern. Als Entwurfsgröße haben Sie die Größe der Belegungseinheit des Speichers $S$ (in Byte).

> Welchen Speicherbedarf haben die beiden Verfahren?

Speicherbedarf von Bitmap: 128 MB / $S$ MB, bspw. 256 Byte bei S=64 KB
Speicherbedarf von Linked List: 
- Knoten: 64 bit = 8 Byte
- Anzahl Blöcke = 128 * 1024 kB / 64 kB = 2048
- Anzahl Lücken/Knoten = 2048 / 2 = 1024
- Größe Knoten = 1024 * 8 Byte = 8192 Byte = 8 kB

> Welches Verfahren ist besser?

Bitmaps sind weniger speicherintensiv, aber Linked Lists sind besser geeignet um Lücken zu finden und zu schließen.

## Aufgabe 7.2
Ein System verwendet Swapping und hat folgende Lücken im Speicher, nach aufsteigender Adresse geordnet: 10 KB, 4KB, 20 KB, 18 KB, 7 KB, 9 KB, 12 KB, 15 KB.

> Welche der Lücken wählen die Seitenersetzungsalgorithmen First Fit, Next Fit, Best Fit und Worst Fit aus, wenn nacheinander Segmente von 12 KB, 10 KB und 9 KB angefordert werden? 
> 
> Bestimmen Sie für die 4 Verfahren auch die Anzahl der freien Blöcke und die mittlere Größe der freien Blöcke!

First-Fit:
- 20 kB (8 kB Rest)
- 10 kB (0 kB Rest)
- 18 kB (9 kB Rest)
- mittlere Größe: 9,14 kB

Next-Fit:
- 20 kB (8 kB Rest)
- 18 kB (8 kB Rest)
- 9 kB (0 kB Rest)
- mittlere Größe: 9,14 kB

Best-Fit:
- 12 kB (0 kB Rest)
- 10 kB (0 kB Rest)
- 9 kB (0 kB Rest)
- mittlere Größe: 12,8 kB

Worst-Fit:
- 20 kB (8 kB Rest)
- 18 kB (8 kB Rest)
- 15 kB (6 kB Rest)
- mittlere Größe: 8 kB

## Aufgabe 7.3
Berechnen Sie die virtuellen Seitennummern und den Offset für die folgenden dezimalen virtuellen Adressen, falls die Seitengröße 4 KB bzw. 8 KB ist: 20000, 32768, 40000, 60000

> Schreiben Sie ein kleines Java Programm, dass die Berechnung durchführt!

## Aufgabe 7.5
Ein Computer mit 32-Bit-Adressen benutzt eine zweistufige Seitentabelle. Virtuelle Adressen werden in ein 10-Bit-Feld für die oberste Seitentabelle, ein 11-Bit-Feld für die zweite Seitentabelle und in einen Offset unterteilt.

> Wie groß sind die Seiten und wie viele Seiten sind im Adressraum?

$32 - 10 - 11 = 11$
$2^{11} = 2048$

Anzahl Seiten: $2^{10} + 2^{11} = 2^{21}$

## Aufgabe 7.6
Der TLB ist Teil der CPU und dient zur Beschleunigung von Datenzugriffen. Betrachten Sie folgendes C-Programm:
```c
int X[N];
int step = M;
for (int i = 0; i < N; i += step) {
	X[i] = X[i] + 1 ;
}
```

a) Das Programm läuft auf einer Maschine mit einer Seitengröße von 4KB. Die TLB kann 64
Einträge aufnehmen. Welche Werte muss N bzw. M besitzen, damit bei jedem Durchlauf der
Schleife ein TLB Fehler verursacht wird?

$M = 4096 / 4 = 1024$
$N ≥ 64 \cdot 1024$

b) Dürfte alles so passen.