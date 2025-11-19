## Aufgabe 8.1
Die Größe des Festplattenplatzes für die ausgelagerten Seiten ist abhängig von der Anzahl der Prozesse $n$, der Anzahl der Bytes im virtuellen Adressraum $v$ und von der Größe des physikalischen Speichers $r$.

> Geben Sie eine Formel für den Speicherbedarf im ungünstigsten Fall an!

$S = n \cdot v - r$

> Bestimmen Sie für ein 32-Bit System die Größe des Festplattenplatzes.

$S = n \cdot 2^{32}~\text{B} - r = n \cdot 4~\text{GB} - r$

> Diskutieren Sie, ob diese Zahl realistisch ist!

Eher nicht, da der Swap sonst bei wenigen Prozessen schon sehr groß wäre.

## Aufgabe 8.2
> Der TLB eines Rechners, der VAX heißt, enthält kein R-Bit. Warum nicht?

Der VAX setzt kein R-Bit, weil er beim ersten Zugriff einen page fault ausführt.

## Aufgabe 8.3
Unser Computer hat 4 Seitenrahmen. Die Tabelle zeigt für jede Seite das R-Bit, das M-Bit, die Ladezeit und die Zeit des letzten Zugriffs. Die Zeiten sind jeweils in Timer-Intervallen angegeben.

| Seite | R-Bit | M-Bit | Ladezeit | Letzter Zugriff |
| ----- | ----- | ----- | -------- | --------------- |
| 0     | 1     | 0     | 126      | 280             |
| 1     | 0     | 1     | 230      | 265             |
| 2     | 0     | 0     | 140      | 270             |
| 3     | 1     | 1     | 110      | 285             |
|       |       |       |          |                 |
> Welche Seite wird zuerst ersetzt durch: NRU, FIFO, LRU, Second Chance?

NRU: 2
FIFO: 3
LRU: 1
Second Chance: 2

## Aufgabe 8.4
Der kleine Computer hat nur 4 Seitenrahmen. Nach dem ersten Timerintervall sind die R-Bits 0111 (Seite 0 hat den Wert 0, die restlichen Seiten den Wert 1). In den folgenden Intervallen sind die Werte 1011, 1010, 1101, 0010, 1010, 1100 und 0001.

> Geben Sie die vier 8 Bit-Zähler eines Aging-Algorithmus nach dem letzten Intervall an!

|     | 0111     | 1011     | 1010     | 1101     | 0010     | 1010      | 1100     | 0001     |
| --- | -------- | -------- | -------- | -------- | -------- | --------- | -------- | -------- |
| 0   | 00000000 | 1000000  | 11000000 | 11100000 | 01110000 | 10111000  | 11011100 | 01101110 |
| 1   | 10000000 | 01000000 | 00100000 | 10010000 | 01001000 | 00100100  | 10010010 | 01001001 |
| 2   | 10000000 | 11000000 | 11100000 | 01110000 | 10111000 | 110111000 | 01101110 | 00110111 |
| 3   | 10000000 | 11000000 | 01100000 | 10110000 | 01011000 | 00101100  | 00010110 | 10001011 |
|     |          |          |          |          |          |           |          |          |

> Welcher Seitenrahmen wird ausgelagert?

Seite 3, weil kleinster Wert.