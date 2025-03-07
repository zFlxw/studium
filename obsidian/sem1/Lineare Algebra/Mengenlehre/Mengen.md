Die Mengenlehre ist ein fundamentaler Bestandteil der  [[Lineare Algebra|linearen Algebra]]. Sie bietet ein einheitliches Konzept zur Beschreibung mathematischer Strukturen. Dabei gibt es verschiedene mathematische Strukturen, die verschiedene Eigenschaften besitzen.

Nach der Definition von <span class="smallcaps">Cantor</span> (1845-1918) ist eine Menge „eine Zusammenfassung $M$ von bestimmten, wohlunterschiedenen Objekten $m$, genannt die Elemente von $M$, unseres Anschauungsraums oder unseres Denkens im Ganzen.“

Eine Menge kann grundsätzlich
- **gar keine Elemente** beinhalten (leere Menge, geschrieben als $\emptyset$ oder $\{\}$),
- **endlich viele Elemente** beinhalten (endliche Menge, wird durch vollständige Auflistung der Elemente geschrieben. Beispiel: $M=\{1,2,3,4,5\}$, $N=\{Auto, 5, \pi\}$, usw.),
- **unendlich viele Elemente** beinhalten (unendliche Menge, kann ggf. auch durch Auflistung beschrieben werden. Beispiel für die Menge der natürlichen Zahlen: $\mathbb{N}=\{1,2,3,4,...\}$)

**Wichtig**: Mengen besitzen **keine** feste Reihenfolge. Das heißt, die Mengen $M=\{1,2,3\}$ und $N=\{3,1,2\}$ sind identisch.

# Teilmengen
Eine Menge $N$ heißt **Teilmenge** von $M$, geschrieben $N\subseteq M$, wenn jedes Element von $N$ auch Element von $M$ ist. Das heißt, $\forall x \in N: x\in M$.

## Schnittmenge
Die **Schnittmenge** von $A$ und $B$, geschrieben $A \cap B$, besteht aus Elementen, die sowohl in $A$ als auch in $B$ vorhanden sind.
$$
A \cap B = \{x\in M \mid x\in A\land x\in B\}
$$
## Vereinigungsmenge
Die **Vereinigungsmenge** von $A$ und $B$, geschrieben $A \cup B$, besteht aus den Elementen, die entweder in $A$ oder in $B$ (oder in beiden) sind.
$$
A \cup B = \{c\in M|x\in A \lor x\in B\}
$$
# Gesetze
Für Teilmengen $A, B, C \subseteq M$ gelten die folgenden Gesetze.

**Kommutativgesetze**:
- $A \cap B = B \cap A$
- $A \cup B = B \cup A$

**Assoziativgesetze:**
- $(A \cap B) \cap C = A \cap (B \cap C)$
- $(A \cup B) \cup C = A \cup (B \cup C)$

**Distributivgesetze:**
- $(A \cap B) \cup C = (A \cup C) \cap (B \cup C)$
- $(A \cup B) \cap C = (A \cap C) \cup (B \cap C)$

**Verschmelzungsgesetze:**
- $A\cap(A\cup B)=A$
- $A\cup(A\cap B)=A$
