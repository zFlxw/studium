Die **lineare Suche** (auch „sequentielle Suche“ oder „linear search“ genannt) ist ein **einfaches** (und ebenfalls das einfachste) [[Suchalgorithmen|Suchverfahren]]. Dieser Algorithmus operiert auf [[Liste|Listen]] und [[Array|Arrays]] und seine Aufgabe besteht darin, iterativ jedes Element in der [[Algorithmen und Datenstrukturen#Datenstruktur|Datenstruktur]] zu durchsuchen, bis das gesuchte Element gefunden wurde.
# Vorgehen
- Iteriere sukzessive über jedes Feld in einem Array
- Überprüfe bei jedem Durchlauf, ob das aktuelle Element dem gesuchten Element entspricht
	- Falls dem so ist → Gebe das aktuelle Element zurück. Der Algorithmus ist beendet.
	- Falls dem nicht so ist → Führe den nächsten Durchlauf aus
- Sollte am Ende kein Element gefunden worden sein, gebe einen „Fehlerwert“ zurück, der signalisiert, dass das gesuchte Element nicht Teil vom Array/ der Liste ist.
# Implementierung
Für die Implementierung des Algorithmus wurde die Programmiersprache [[C]] verwendet.
```c
int linear_search(int array[], int length, int key) {
	for (int i = 0; i < length; i++) {
		if (array[i] == key) {
			return array[i];
		}
	}

	return -1;
}
```
# Laufzeitanalyse
Wie bereits im Kapitel [[Laufzeit#Big-Oh Notation]] erwähnt, wird die Laufzeit eines Algorithmus meistens in „Best Case“, „Average Case“ und „Worst Case“ unterteilt.

Der beste anzunehmende Fall bei der linearen Suche ist, dass das gesuchte Element an erster Stelle des Arrays oder der Liste steht. Wenn das der Fall ist, muss die Schleife lediglich einmal durchlaufen werden und wir hätten somit eine **untere Schranke** $\Omega(1)$.

Der worst-case hingegen wäre, wenn das Element an letzter Stelle, bzw. gar nicht im Array oder der Liste vorkommt. Dann müssten wir alle Elemente vergleichen und somit über das ganze Array iterieren. Damit haben wir eine **obere Schranke** von $O(N)$.

Für den durchschnittlichen Fall gehen wir davon aus, dass das gesuchte Element in den meisten Fällen irgendwo zufällig im Array liegt. Das kann mal weiter vorne oder auch mal weiter hinten sein. Wenn wir uns überlegen, dass wir den Algorithmus sehr oft durchlaufen lassen und jedes Mal ein Element suchen, das an einer zufälligen Stelle im Array liegt, können wir davon ausgehen, dass der Algorithmus durchschnittlich $\frac{1}{2}N$ Durchläufe benötigt, um das Element zu finden. Da in der [[Laufzeit#Big-Oh Notation|Big-Oh Notation]] der Koeffizient vernachlässigt wird, ist der durchschnittliche Fall $\Theta(N$), also gleich wie die obere Schranke.

Zusammengefasst ist die Laufzeit also:

| Fall         | Laufzeit (Tilde-Notation) | Laufzeit (Oh-Notation) |
| ------------ | ------------------------- | ---------------------- |
| Best Case    | $\sim 1$                  | $\Omega(1)$            |
| Average Case | $\sim \frac{1}{2}N$       | $\Theta(N)$            |
| Worst Case   | $\sim N$                  | $O(N)$                 |
