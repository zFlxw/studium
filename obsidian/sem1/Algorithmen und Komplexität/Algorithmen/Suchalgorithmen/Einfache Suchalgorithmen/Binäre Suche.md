Die **binäre Suche** (binary search) ist ein **einfaches** [[Suchalgorithmen|Suchverfahren]], welches effizient auf einer [[Liste]] oder einem [[Array]] Elemente suchen kann. Die Voraussetzung für die Anwendung der binären Suche ist, dass das Array **aufsteigend** oder **absteigend** sortiert ist und der Algorithmus die Sortierrichtung kennt.
# Vorgehen
*Hinweis:* Nachfolgendes Vorgehen bezieht sich auf ein **aufsteigend** sortiertes Array.
- Springe in die Mitte des Arrays/ der Liste und überprüfe, ob das Element an diesem Index dem gesuchten Element entspricht
	- Falls **ja** → Gib dieses Element zurück. Der Algorithmus ist beendet.
	- Falls **nein** → Überprüfe, ob das gesuchte Element größer oder kleiner als das aktuelle Element ist.
		- Ist das Element größer → Springe in die Mitte des rechten Teilarrays (`[aktuelles Element < x < length]` und wiederhole das Vorgehen.
		- Ist das Element kleiner → Springe in die Mitte des linken Teilarrays (`[0 < x < aktuelles Element]`) und wiederhole das Vorgehen.
- Sollte am Ende kein Element gefunden worden sein, gib einen „Fehlerwert“ zurück. Der Algorithmus ist beendet.
# Implementierung
Die binäre Suche kann auf zwei Arten implementiert werden: **iterativ** und **rekursiv**. Nachfolgend werden beide Implementierungen in der Programmiersprache [[C]] gezeigt.
## iterative Implementierung
```c
int binary_search(int array[], int length, int key) {
	int low = 0, high = length - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (array[mid] == key) {
			return array[mid];
		}

		if (array[mid] < key) {
			low = mid + 1;
		} else if (array[mid] > key) {
			high = mid - 1;
		}
	}

	return -1;
}
```
## rekursive Implementierung
```c
int binary_search(int array[], int key, int low, int high) {
	if (low > high) {
		return -1;
	}

	int mid = (low + high) / 2;

	if (array[mid] == key) {
		return key;
	}

	if (array[mid] < key) {
		return binary_search(array, key, mid + 1, high);
	}

	if (array[mid] > key) {
		return binary_search(array, key, low, mid - 1);
	}
}
```
# Laufzeitanalyse
Der günstigste Fall, der bei der binären Suche eintreten kann ist, dass das Element in der Mitte des Arrays liegt und somit direkt beim ersten Vergleich gefunden wird. Damit wäre die **untere Schranke** $\Omega(1)$.

Der schlechteste Fall ist, dass das Element gar nicht im Array vorkommt. Dadurch, dass die binäre Suche mit Rekursion, bzw. Abbruchbedingungen innerhalb einer Schleife arbeitet, ist die Ermittlung der Laufzeitkomplexität etwas schwieriger.  

*Und wie findet man raus, bei welcher Eingabe der schlechteste Fall eintritt?* Zunächst bedenken wir, dass der Algorithmus nicht linear über die Liste, bzw. das Array iteriert, sondern mit jedem Durchlauf die Eingabegröße $n$ solange **halbiert**, bis am Ende nur noch ein Teilarray der Größe $1$ auftritt. Das bedeutet, wenn der Algorithmus dafür $k$ Durchläufe benötigt, gilt
$$
\frac{n}{2^k}=1
$$
Wir müssen nun die Anzahl der Durchläufe $k$ berechnen (da das eben die Anzahl der Durchläufe ist, bis der worst case eintritt). Dazu formen wir die Gleichung zunächst um und lösen anschließend nach $k$ auf.
$$
n=2^k\enspace\Longrightarrow\enspace k=\log(n)
$$
*Hinweis: In der Informatik meint ein Logarithmus, bei dem keine Basis explizit angegeben ist, typischerweise den Logarithmus Dualis - also den Logarithmus zur Basis $2$.*

Somit haben wir nun bestimmt, dass die **obere Schranke** bei der binären Suche bei $O(log(N))$ liegt. Der „average case“ ist ebenfalls gleich der oberen Schranke, also $\Theta(log(N))$.