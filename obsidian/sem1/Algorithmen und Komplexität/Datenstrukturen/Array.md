Ein **Array** ist eine **lineare** und **statische** [[Algorithmen und Datenstrukturen#Datenstruktur|Datenstruktur]], die eine endliche Abfolge von Objekten speichert. „Linear“ bedeutet in diesem Kontext, dass die Elemente der Datenstruktur in einem kohärenten Datenblock im Arbeitsspeicher gespeichert werden. „Statisch“ heißt, dass die Größe der Datenstruktur, bzw. die Anzahl der Elemente, die sie speichern kann, einmal festgelegt wird und nicht dynamisch zur Laufzeit des Programms angepasst werden kann.
# Datenrepräsentation
Ein Array speichert Daten in einem durchgängigen Block im Arbeitsspeicher:
![[Pasted image 20250103215808.png]]*Quelle: https://beginnersbook.com/wp-content/uploads/2018/10/array.jpg (Stand: 03.01.2025)*

In der Grafik wird jedes Element im Array als Zelle repräsentiert. Über der Zelle steht jeweils die Adresse im Arbeitsspeicher (symbolisch dargestellt; normalerweise werden Speicheradressen in Hexadezimalform angegeben). Unterhalb der Zelle befindet sich der **Index** des Elements (also die Stelle im Array).
# Operationen
## Daten auslesen
Damit ein einfacher Datenzugriff möglich ist, können in einem Array typischerweise nur Daten vom gleichen Datentypen gespeichert werden (also zum Beispiel nur Integer, nur Character, usw.). 

*Warum?* Wenn alle Elemente den gleichen Datentyp (also auch die gleiche Speichergröße) besitzen, kann die Speicheradresse jedes Elements im Array einfach mit folgender Gleichung über den Index berechnet werden:
$$
\text{elem\_addr} = \text{start\_addr} + i\cdot \text{size}
$$
$\text{start\_addr}$ ist die Adresse des ersten Elements im Array (bzw. auch die Adresse des Arrays im Allgemeinen), $i$ ist der Index des gesuchten Elements (also die Stelle im Array) und $\text{size}$ die Größe eines Elements im Array. Diese Gleichung geht aber nur dann auf, wenn $\text{size}$ für jedes Element identisch ist, was bei unterschiedlichen Datentypen nicht zwingend gegeben wäre.

Der Zugriff auf die Daten erfolgt also einfach über einen Index (da die restlichen Variablen der Gleichung beim Definieren des Arrays bekannt sind).

## Daten einfügen
Das Einfügen der Daten erfolgt ebenfalls einfach über den Index. Je nach Sprache muss hierbei nur darauf geachtet werden, dass der Index nicht den vom Array allokierten Speicher überschreitet (wenn das Array nur $10$ Elemente halten kann, kann bspw. an der 11. Position kein Element mehr eingefügt werden). Je nach Programmiersprache wird entweder ein Fehler geworfen oder - wie beispielsweise in [[C]] - es wird unbefugt auf fremden Speicher zugegriffen.

Wenn ein Element in der Mitte des Arrays eingefügt werden soll, ohne dass dafür ein anderer Wert überschrieben werden soll, muss genug Speicherplatz zur Verfügung stehen, sodass bisherigen Elemente, die nach dem zu verschiebenden Element auftreten, um eine Position nach hinten verschoben werden können

## Daten löschen
Um ein Element aus einem Array zu löschen, überschreibt man entweder den Speicher am Index des Elements mit einem leeren Wert (z.B. `0` oder `NULL`) oder - wenn das Array keine Lücken enthalten soll - man verschiebt alle Elemente ab dem Index des zu löschenden Elements um eine Position nach vorne. Damit wird das zu löschende Element durch seinen Nachfolger überschrieben und es entsteht keine Lücke.

# Laufzeitanalyse

| Operation | Laufzeit (Best Case) | Laufzeit (Average Case) | Laufzeit (Worst Case) |
| --------- | -------------------- | ----------------------- | --------------------- |
| Lesen     | $O(1)$               | $O(1)$                  | $O(1)$                |
| Einfügen  | $O(1)$               | $O(N)$                  | $O(N)$                |
| Löschen   | $O(1)$               | $O(N)$                  | $O(N)$                |
