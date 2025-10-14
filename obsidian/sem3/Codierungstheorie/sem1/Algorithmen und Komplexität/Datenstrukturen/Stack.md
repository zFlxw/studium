Ein **Stack** ist eine dynamische [[Algorithmen und Datenstrukturen#Datenstruktur|Datenstruktur]], die eine endliche Abfolge von Daten speichert. Die Besonderheit hier ist, dass ein Stack nach dem „Last In First Out“ (LIFO) Prinzip funktioniert. Das bedeutet, dass lediglich auf das erste Element des Stacks zugegriffen werden kann, was in dem Fall das Element ist, das **zuletzt** zum Stack hinzugefügt wurde.

# Datenrepräsentation
Ein Stack wird oft auf Basis eines dynamischen [[Array|Arrays]] oder einer [[Liste|Linked List]] implementiert.

Visuell kann man sich einen Stack also wie einen Bücherstapel vorstellen. Hier nimmt man normalerweise auch das obere Buch vom Stapel und kann nicht direkt auf die unteren Bücher zugreifen.
![[Pasted image 20250114194751.png]]
*Quelle: https://gochocit.com/wp-content/uploads/2021/11/minh-hoa-stack.png (14.01.2025)*

# Datenzugriff (Stack API)
Bei einem Stack ist es nicht möglich auf alle Daten zuzugreifen, sondern nur auf das erste Element. Ein Stack unterstützt dabei die folgenden Operationen:

| Methode      | Beschreibung                                                     |
| ------------ | ---------------------------------------------------------------- |
| `push(item)` | Fügt ein Element zum Stack hinzu (an oberster Stelle)            |
| `pop()`      | Entfernt das oberste Element des Stacks und gibt es zurück       |
| `peek()`     | Gibt das oberste Element des Stacks zurück, ohne es zu entfernen |
| `size()`     | Gibt die Anzahl an Elementen im Stack zurück                     |
# Implementierung (Liste)
Bei der Implementierung eines Stacks mit einer Liste, ist es sinnvoll das oberste Element des Stacks als erstes Element der Liste zu speichern, da somit immer klar ist, wo das oberste Element ist und so für die Suche immer eine Zeitkomplexität von $O(1)$ besteht.
```embed-c
PATH: "vault://sem1/Algorithmen und Komplexität/_code/stack.c"
TITLE: "Stack Implementierung (Liste)"
```





