Ein Häufungspunkt ist ein Punkt, in dessen Nähe unendlich viele Glieder einer [[Folgen|Folge]] liegen.

Sei $(a_n)$ eine Folge und $x\in\mathbb{R}$. $x$ ist ein Häufungspunkt, g. d. w. für jede $\varepsilon$-**Umgebung** $U_\varepsilon(x)=(x-\varepsilon,x+\varepsilon)$ mit $\varepsilon>0$ unendlich viele Glieder der Folge $(a_n)$ in $U_\varepsilon(x)$ liegen.

## Beispiele
### Beispiel 1
Die Folge $(a_n)_{n\ge\mathbb{N}}$ sei definiert als:
$$
a_n := \begin{cases}
\dfrac{1}{n},\enspace\text{für n gerade}\\
1 \enspace\enspace~ \text{sonst}
\end{cases}
$$
Betrachtet man die Teilfolge aller ungeraden Indizes, wird diese als
$$
a_{n_k}=a_{2n-1}=1\enspace\text{für alle}~n_k~\text{ungerade} 
$$
notiert. Da es sich hierbei um eine konstante Teilfolge handelt, die aus den gleichen Gliedern besteht, gibt es für jede $\varepsilon$-Umgebung um $1$ unendlich viele Glieder der Teilfolge. Daher ist $1$ ein Häufungspunkt.

Betrachtet man die Teilfolge aller geraden Indizes, also
$$
a_{n_k}=a_{2n}=\frac{1}{n}\enspace\text{für alle}~n_k~\text{gerade}
$$
Mit wachsendem $n$ nähert sich diese Folge immer weiter $0$ an, ohne diesen Wert jemals zu erreichen. Das bedeutet, für jedes $\varepsilon>0$ gibt es eine $\varepsilon$-Umgebung
$$
U_\varepsilon(x)=(x-\varepsilon,x+\varepsilon)
$$
in der immer für ein genügend größes $n>N$ (also alle Folgenglieder mit Index $n$ ab einem Mindestindex $N$) unendlich viele Glieder der Teilfolge in der Folge liegen. Daher ist $0$ ebenfalls ein Häufungspunkt der Folge.
