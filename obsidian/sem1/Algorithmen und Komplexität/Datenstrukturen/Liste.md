Eine Liste (bzw. „Linked List“ oder „Verkettete Liste“) ist eine **nichtlineare** und **dynamische** [[Algorithmen und Datenstrukturen#Datenstruktur|Datenstruktur]], die Elemente geordnet speichert. „Nichtlinear“ bedeutet in diesem Fall, dass die Elemente einer Linked List verteilt im Arbeitsspeicher liegen können und nicht zwingend in einem durchgängigen Block gespeichert sind. „Dynamisch“ bedeutet, dass sich die Größe der Liste zur Laufzeit verändern kann.

# Datenrepräsentation
Die Daten, die in einer Liste gespeichert werden sollen, werden in sogenannte **Nodes**  verpackt. Eine Node besteht aus einem `data` Feld, welches die Daten des Elements beinhaltet und einem `next`-Pointer, der auf das nächste Element in der Liste zeigt.
![[Pasted image 20250105122941.png]]
*Quelle: https://www.freecodecamp.org/news/how-linked-lists-work/ (Stand 05.01.2025)*

Die Linked List selbst speichert nur einen Pointer zur ersten Node, welche auch als**head** oder **root** bezeichnet wird. Außerdem nennt man das letzte Element auch **tail**.

# Daten lesen
Der Zugriff auf die Daten in einer Linked List erfolgt wie bei [[Array|Arrays]] über einen Index. Hier kann man allerdings nicht einfach die Speicheradresse berechnen, da die Nodes nicht zwingend in einem Block im Arbeitsspeicher liegen und der Linked List lediglich die Speicheradresse der ersten Node , dieser Node lediglich die Speicheradresse der nächsten Node bekannt ist, usw. Möchte man also das Element am $i$-ten Index finden, beginnt man bei der Root-Node und folgt $i$-mal dem `next`-Pointer

# Daten einfügen und löschen
Das Einfügen und Löschen von Daten hingegen ist bei einer Linked List recht einfach: Um ein Element einzufügen, muss man lediglich den `next`-Pointer von dem vorherigen Element auf das neu eingefügte Element legen und den `next`-Pointer des eingefügten Arrays auf den ursprünglichen `next`-Pointer des Vorgängers setzen. Beim Löschen wird dann einfach der `next`-Pointer vom Vorgänger des zu löschenden Elements auf das nachfolgende Element gelegt und fertig.

# Laufzeitanalyse

| Operation | Laufzeit (Best Case) | Laufzeit (Average Case)       | Laufzeit (Worst Case)         |
| --------- | -------------------- | ----------------------------- | ----------------------------- |
| Lesen     | $O(1)$               | $O(N)$                        | $O(N)$                        |
| Einfügen  | $O(1)$               | $O(1)$, wenn Node bekannt ist | $O(1)$, wenn Node bekannt ist |
| Löschen   | $O(1)$               | $O(1)$, wenn Node bekannt ist | $O(1)$, wenn Node bekannt ist |
Sollte die Node nicht bekannt sein, muss diese erst gesucht werden. Es entsteht also eine Kombination aus Lese- und Einfügeoperation, womit sich die Laufzeit auf $O(N)$ verschlechtert.