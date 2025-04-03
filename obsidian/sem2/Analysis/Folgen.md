## Definition
Eine **Folge** ist eine geordnete Auflistung von endlich oder abzählbar unendlich vielen reellen Zahlen, die aufsteigend durchnummeriert sind.

**Notation**
- endliche Folge: $(a_n)_{n=1,\ldots,m}=(a_1,a_2,\ldots,a_m)$
- unendliche Folge: $(a_n)_{n\ge 1}=(a_n)_{n\in\mathbb{N}}=(a_1,a_2,\ldots)$

## Teilfolge
Eine **Teilfolge** ist eine neue Folge, die aus einer bereits vorhandenen Folge entsteht, indem beliebig viele Glieder weggelassen werden. Die ursprüngliche Reihenfolge der Glieder darf jedoch **nicht** modifiziert werden.

Sei $(n_k)$ mit $n_k\in\mathbb{N}$ und $n_1<n_2<n_3<\cdots$ eine Indexfolge. Die Teilfolge besteht besteht aus den Elementen
$$
a_{n_1},a_{n_2},a_{n_3}, \dots
$$

## Beschränkte Folgen
Eine Folge $(a_n)$ heißt **beschränkt**, wenn es eine untere Grenze $m$ und eine obere Grenze $M$ gibt, sodass gilt:
$$
m \le a_n \le M
$$
Alternativ lässt sich auch sagen, dass es in einer beschränkten Folge ein $K\ge 0$ geben muss, sodass $|a_n|\le K$ für alle $n\in\mathbb{N}$.

### Typen der Beschränktheit
Eine Folge ist nach oben beschränkt, wenn gilt $\forall n\in\mathbb{N}: a_n\le M$. Die kleinste obere Schranke nennt man **Supremum**.

Eine Folge ist nach unten beschränkt, wenn gilt: $\forall n\in\mathbb{N}: m\le (a_n)$. Die größte untere Schranke nennt man **Infimum**.

Ist eine Funktion beidseitig beschränkt, sprich man von einer **beschränkten Funktion**.

## Grenzwerte von Folgen
Besitzt eine Funktion genau einen Häufungspunkt, nennt man diesen den **Grenzwert** der Funktion.

**Def.** Ein $a\in\mathbb{R}$ heißt Grenzwert einer Folge $(a_n)_{n\ge 1}$ wenn es zu jedem $\varepsilon>0$ ein $N=N_\varepsilon \in \mathbb{N}$ gibt mit $|a_n-a|<\varepsilon$ für alle $n\ge N$.

Kurz ausgedrückt:
$$
\forall\varepsilon>0\exists N\in\mathbb{N}\forall n\ge N:|a_n-a|<\varepsilon
$$
