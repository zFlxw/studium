## Visuelle Herleitung
Um zu verstehen, was Eigenwerte und Eigenvektoren sind, müssen wir zunächst verstehen, was die Werte einer Matrix repräsentieren.

Wir betrachten einen zweidimensionalen Vektorraum mit den Basisvektoren $i=\begin{pmatrix}1\\0\end{pmatrix}$ und $j=\begin{pmatrix}0\\1\end{pmatrix}$. Diesen Vektorraum bilden wir nun auf einen anderen Vektorraum mit den Basisvektoren $\hat{i}=\begin{pmatrix}3\\0\end{pmatrix}$ und $\hat{j}=\begin{pmatrix}1\\2\end{pmatrix}$ ab.

## Definition (mathematisch)
Multiplizieren wir eine Matrix $A$ mit einem Vektor $\vec{v}$ und es gilt die Gleichung
$$
A\cdot\vec{v}=\lambda\cdot\vec{v}
$$
dann bedeutet das, dass das Ergebnis der Matrix-Vektor-Multiplikation lediglich den **skalierten Vektor** $\vec{v}$ ergibt. Den Vorfaktor $\lambda$ bezeichnen wir dann als **Eigenwert** und den Vektor $\vec{v}$ **Eigenvektor**.

Eigenwerte und Eigenvektoren existieren **nur in quadratischen Matrizen**. Das liegt daran, dass das Ergebnis einer Vektor-Matrix-Multiplikation, bei der die Matrix $A$ in $\mathbb{R}^{n\times m}$ ($n\ne m$) liegt, in einem anderen Raum landet (z.B. $\mathbb{R}^n$ oder $\mathbb{R}^m$).
## Berechnung der Eigenwerte
Sei $A$ eine $n\times n$-Matrix, zu der wir die Eigenwerte und -vektoren berechnen wollen.

**Schritt 1**
Im ersten Schritt bilden wir die Matrix $A-\lambda E_n$, also sprich die Differenz aus der gegeben Matrix und der um $\lambda$ skalierten **Einheitsmatrix**. Dadurch subtrahieren wir die Diagonale der Matrix $A$ mit $\lambda$.

**Schritt 2**
Wir berechnen die **Determinante** der Matrix. Diese nennen wir nun das **charakteristische Polynom** $\chi_A(\lambda)$. Dieses berechnen wir mit der Gleichung
$$
\chi_A(\lambda)=\det(A-\lambda E_n)
$$
**Schritt 3**
Nun bestimmen wir die **Nullstellen des charakteristischen Polynoms**. Das sind dann die gesuchten Eigenwerte.

### Beispiel
Gegeben ist die $3\times 3$-Matrix
$$
A=\begin{pmatrix}
2 & 1 & 2 \\
1 & 2 & 2 \\
1 & 1 & 3
\end{pmatrix}
$$
Zunächst berechnen wir die Matrix $A-\lambda E_n$ :
$$
(A-\lambda E_n)=
\begin{pmatrix}
2 & 1 & 2 \\
1 & 2 & 2 \\
1 & 1 & 3 \\
\end{pmatrix}
-
\begin{pmatrix}
\lambda & 0 & 0 \\
0 & \lambda & 0 \\
0 & 0 & \lambda \\
\end{pmatrix}
=
\begin{pmatrix}
2-\lambda & 1 & 2 \\
1 & 2-\lambda & 2 \\
1 & 1 & 3-\lambda \\
\end{pmatrix}
$$
Anschließend berechnen wir die Determinante der Matrix $(A-\lambda E_n)$
$$
\begin{align}
\det 
\begin{pmatrix}
2-\lambda & 1 & 2 \\
1 & 2-\lambda & 2 \\
1 & 1 & 3-\lambda \\
\end{pmatrix}
&=
(2-\lambda)^2\cdot(3-\lambda)+2+2-2(2-\lambda)-2(2-\lambda)-(3-\lambda) \\
&=
-\lambda^3 + 7\lambda^2 - 11\lambda + 5\\
&=
(\lambda - 1)(-\lambda^2 + 6\lambda - 5)
\end{align}
$$
$(\lambda-1)$ ergibt sich durch Raten einer Nullstelle. Hierbei wurde die Nullstelle $1$ gefunden, da $-(1)^3+7(1)^2-11(1)+5 = 0$.

Die anderen beiden Nullstellen lassen sich beispielweise durch die **Mitternachtsformel** oder die **pq-Formel** bestimmen.
$$
\begin{align}
\lambda_{2,3}&=\frac{-6\pm\sqrt{6^2-4(-1)(-5)}}{2(-1)} \\
\lambda_2&=\frac{-6+\sqrt{16}}{-2}=1\\
\lambda_3&=\frac{-6-\sqrt{16}}{-2}=5
\end{align}
$$
Somit sind die Nullstellen der Determinante von $(A-\lambda E_n)$:
$\qquad \lambda_1=1;\quad\lambda_2=1;\quad \lambda_3=5$

Diese Nullstellen sind nun die **Eigenwerte**.

## Berechnung der Eigenvektoren
Damit wir die Eigenvektoren bestimmen können, müssen wir im Vorfeld die Eigenwerte bestimmt haben.

Um die Eigenvektoren zu bestimmen, wählen wir einen der Eigenwerte und setzen ihn in die Gleichung $(A-\lambda E_n)=0$ ein. Wir schließen hier an das obige Beispiel an und wählen für $\lambda = 1$:
$$
\begin{align}
(A-\lambda E_n)\cdot\vec{v} &= 0 \\
\begin{pmatrix}
2-1 & 1 & 2 \\
1 & 2-1 & 2 \\
1 & 1 & 3-1 \\
\end{pmatrix}
\cdot
\begin{pmatrix}
v_1 \\
v_2 \\
v_3 \\
\end{pmatrix}
&=
\begin{pmatrix}
0 \\
0 \\
0 \\
\end{pmatrix} \\
\begin{pmatrix}
1 & 1 & 2 \\
1 & 1 & 2 \\
1 & 1 & 2 \\
\end{pmatrix}
\cdot
\begin{pmatrix}
v_1 \\
v_2 \\
v_3 \\
\end{pmatrix}
&=
\begin{pmatrix}
0 \\
0 \\
0 \\
\end{pmatrix} \\
\end{align}
$$
Reduzieren wir dieses Gleichungssystem nun um die redundanten Zeilen, so erhalten wir
$$
\begin{pmatrix}
1 & 1 & 2 \\
0 & 0 & 0 \\
0 & 0 & 0 \\
\end{pmatrix}
\cdot
\begin{pmatrix}
v_1 \\
v_2 \\
v_3
\end{pmatrix}
=
\begin{pmatrix}
0 \\
0 \\
0
\end{pmatrix}
$$
und somit lässt sich das Gleichungssystem auf die Gleichung
$$
v_1+v_2+2v_3=0
$$
reduzieren. Die restlichen Zeilen sind trivial und wir erhalten somit zwei freie Variablen. Die freien Variablen bezeichnen wir nachfolgend mit $a$ und $b$. wobei $a = v_2$ und $b = v_3$ gilt.

Nun stellen wir die Gleichung beispielsweise nach $v_1$ um und erhalten somit
$$
v_1=-v_2-2v_3=-a-2b
$$
In einem Vektor dargestellt sieht das nun so aus:
$$
\vec{v}
=
\begin{pmatrix}
-a-2b \\
a \\
b
\end{pmatrix}
=
a
\begin{pmatrix}
-1 \\
1 \\
0
\end{pmatrix}
+
b
\begin{pmatrix}
-2 \\
0 \\
1
\end{pmatrix}
$$
Somit erhalten wir die beiden Eigenvektoren
$$
\mathbb{L}=\left\{
\begin{align}
a
\begin{pmatrix}
-1 \\
1 \\
0
\end{pmatrix}+b
\begin{pmatrix}
-2 \\
0 \\
1
\end{pmatrix}
\end{align}
\vert~
a,b\in\mathbb{R}
\right\}
$$
## Eigenraum
Am letzten Beispiel erkennen wir, dass es zu einem Eigenwert nicht zwingend einen einzigen Eigenvektor gibt, sondern gegebenenfalls können mehrere Eigenvektoren existieren. Vereinigen wir nun 