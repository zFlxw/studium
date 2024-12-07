## Definition (mathematisch)
Eine **lineare Abbildung** zwischen zwei Vektorräumen $V$ und $W$, die beide über dem gleichen Körper $\mathbb{K}$ liegen, ist erstmal einfach eine Funktion $f: V \longrightarrow W$, die zwei Eigenschaften besitzen muss:
- $f(v+w)=f(v)+f(w)$ mit $v\in V, w\in W$ (Additivität)
- $f(\lambda\cdot v) = \lambda f(v)$ mit $v\in V, k \in \mathbb{K}$ (Homogenität)

## Definition (visuell)
Wir können uns eine lineare Abbildung so vorstellen, dass wir den Vektorraum "verzerren", indem wir jeden Vektor aus dem Vektorraum $V$ auf einen Punkt im Vektorraum $W$ abbilden, wobei wichtig ist, dass dies nicht willkürlich passiert, sondern folgende Eigenschaften erhalten bleiben:
- Der Ursprung ist fix und verschiebt sich nicht
- Alle Linien bleiben parallel zueinander und der Abstand zwischen den Linien ist konstant
Stellen wir uns vor, dass jeder Vektor zu einem Punkt in $V$ nun auf einen anderen Punkt in $W$ zeigt, dann können wir uns das bildlich so vorstellen, dass sich die Gridlines vom Koordinatensystem verschieben.

Beispiel: Wir betrachten einen zweidimensionalen Vektorraum $V$ mit den Basisvektoren $\vec{v}=\begin{pmatrix}1\\0\end{pmatrix}$ und $\vec{w}=\begin{pmatrix}0\\1\end{pmatrix}$. Tragen wir diese Vektoren in ein Koordinatensystem ein, sieht das so aus:
![[Pasted image 20241207105459.png|center]]
Nun bilden wir den Vektor $\vec{v}$ auf den Vektor $\hat{v}=\begin{pmatrix}2\\1\end{pmatrix}$ und $\vec{w}$ auf $\hat{w}=\begin{pmatrix}1\\2\end{pmatrix}$ ab. Aus den oben genannten Eigenschaften geht hervor, dass sich jeder andere Vektor in dem Raum nun ebenfalls verschieben muss, damit die Abbildung linear ist. Damit verschiebt sich das "Muster" des Koordinatensystems:
![[Pasted image 20241207110144.png|center]]
## Hinführung zu Matrizen
Wie bereits erwähnt verschiebt sich bei einer linearen Abbildung jeder Vektor, jedoch haben wir auch gesehen, dass wir lediglich die Verschiebung der beiden Basisvektoren betrachten müssen und daraus ableiten können, wie sich alle anderen Vektoren verschieben (da durch die Eigenschaften einer linearen Abbildung gegeben ist, dass die Verschiebung nicht willkürlich ist, sondern immer einem festen Muster folgt).

Es genügt also die Koordinaten zu kennen, an denen die Basisvektoren landen. Diese Koordinaten können zu einer Matrix zusammengefasst werden. Für unser vorheriges Beispiel sähe die Matrix so aus:
$$
A
=
\begin{pmatrix}
2 & 1 \\
1 & 2
\end{pmatrix}
$$
