## Priority Queue
- basiert auf Queue
- Löscht nicht das erste Element, sondern das größte (oder kleinste)
- Beispiel:
	- A = [1, 4, 5, 9, 2]
	- `removeMax(A); // Löscht 9;`
- Zeitkomplexität basiert auf Implementierung

| Implementierung    | Insert   | Max      | Delete   |
| ------------------ | -------- | -------- | -------- |
| Unsortiertes Array | O(1)     | O(n)     | O(n)     |
| Sortiertes Array   | O(n)     | O(1)     | O(1)     |
| Ziel               | O(log n) | O(log n) | O(log n) |
