Die **Prädikatenlogik** baut auf der [[Elementare Aussagenlogik|elementaren Aussagenlogik]] auf und erweitert sie dahingehend, dass nun ebenfalls das „innere“ einer Aussage betrachtet wird. Das bedeutet, dass sich Aussagen durch Unbekannte erweitern lassen (ähnlich wie bei [[Funktionen]]).

**Beispiel**: *$x$ ist ein Mensch* lässt sich prädikatenlogisch folgendermaßen darstellen
$$
A(x): x~\textit{ist ein Mensch}
$$
# Quantoren
Quantoren bestimmen den Geltungsbereich von Aussagen über Variablen. Dabei gibt es die folgenden beiden Quantoren:
- **Allquantor** ($\forall$): Dieser Quantor gibt an, dass eine Aussage **für alle** Elemente der betrachteten Menge gilt. 
  *Beispiel: $\forall x \in M: A(x)$. Für alle $x$ der Menge $M$ gilt die Aussage $A(x)$.*
- **Existenzquantor** ($\exists$): Dieser Quantor gibt an, dass es mindestens ein Element in der betrachteten Menge gibt, für das die Aussage gilt.
  *Beispiel: $\exists x\in M: A(x)$. Es existiert ein $x$ in der Menge $M$ für das die Aussage $A(x)$ gilt*

Darüber hinaus kann mit dem **Eindeutigkeitsquantor** weiter spezifiziert werden, dass es nur genau $n$ Elemente gibt, für die die Aussage gilt:
- $\exists!x A(x)$ *Es existiert genau ein $x$ für das die Aussage $A(x)$ gilt.*
- $\exists^{=2}x A(x)$ *Es existieren genau zwei $x$ für die die Aussage $A(x)$ gilt.*
