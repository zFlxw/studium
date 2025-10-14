Die Mathematik ist eine exakte Wissenschaft. Das bedeutet, Behauptungen können bewiesen werden. Dazu gibt es verschiedene Beweistechniken, die sich je nach Behauptung besser oder schlechter eignen.

# Direkter Beweis
Der direkte Beweis zeigt durch logische Schlussfolgerung, dass eine Behauptung wahr ist.

**Beispiel**: *Die Summe von drei aufeinanderfolgenden natürlichen Zahlen ist durch 3 teilbar.*
Sei $n \in \mathbb{N}$, dann gilt:
$$
n+(n+1)+(n+2)~ ~\text{ist durch 3 teilbar}
$$
Wenn $n$ eine natürliche Zahl ist, ist auch $n+1$ eine natürliche Zahl. Durch Umformung ergibt sich:
$$
n+(n+1)+(n+2)=3n+3=3\cdot(n+1)
$$
Wir sehen, dass $3$ ein Faktor der Aussage ist. Ist $k$ eine natürliche Zahl, dann ist $3\cdot k$ durch drei teilbar. Daraus folgt, dass $3\cdot(n+1)$ durch $3$ teilbar ist.

# Indirekter Beweis (Widerspruchsbeweis)
Beim indirekten Beweis gehen wir davon aus, dass eine Aussage nicht gilt (wir gehen also von $\lnot A$ aus) und führen diese Aussage dann zum logischen Widerspruch.

**Beispiel**: *Die Summe von drei aufeinanderfolgenden natürlichen Zahlen ist durch 3 teilbar.*
Widerspruchsannahme: $n$ ist eine natürliche Zahl und $n+(n+1)+(n+2)$ ist nicht durch $3$ teilbar.

Formen wir die Summe wieder um, erhalten wir:
$$
3n+3 = 3\cdot(n+1)
$$
Damit $3\cdot k$ nicht durch drei teilbar ist, muss $k$ keine natürliche Zahl sein. $k$ ist in diesem Fall $(n+1)$. Stellen wir nach $n$ um erhalten wir
$$
\begin{align}
3n + 3 = 3 \cdot (n + 1)\enspace &\mid \div3 \\
n+1=n+1\enspace &\mid -1 \\
(n+1)-1=n \enspace
\end{align}
$$
Damit führen wir die Aussage zu einem Widerspruch, da $n$ per Definition eine natürliche Zahl sein muss, $3\cdot k$ jedoch nur dann nicht durch drei teilbar ist, wenn $k$ keine natürliche Zahl ist.


# Induktionsbeweis
Der Beweis durch vollständige Induktion ist eine wichtige Beweistechnik, bei der eine Behauptung für alle natürlichen Zahlen bewiesen wird. Der Aufbau eines Induktionsbeweis sieht dabei so aus:
1. **Induktionsanfang**: Die Behauptung wird für ein beliebiges $n$ aus den natürlichen Zahlen bewiesen (meist $n=0$ oder $n=1$).
2. **Induktionsbehauptung**: Wir nehmen an, dass wenn die Aussage für $n$ stimmt, dass sie auch für $n+1$ stimmen muss.
3. **Induktionsschritt**: Diese Behauptung wird im Induktionsschritt durch logische Schlussfolgerung bewiesen.

**Beispiel**: Ein typisches Beispiel für einen Beweis durch vollständige Induktion ist die **Gaußsche Summenformel**
$$
\sum\limits_{k=1}^{n}k=\dfrac{n(n+1)}{2}
$$
_Schritt 1: Induktionsanfang_
Sei $n\in\mathbb{N}$, dann gilt für $n=1$
$$
\sum\limits_{k=1}^{1}=1=\dfrac{1(1+1)}{2}
$$
Damit ist die **Induktionsvoraussetzung** erfüllt, da $\exists n\in\mathbb{N}: \sum\limits_{k=1}^{n}k=\dfrac{n(n+1)}{2}$.
*Schritt 2: Induktionsbehauptung*
Wir haben gezeigt, dass die Gleichung für $n=1$ gilt. Nun behaupten wir, dass wenn die Gleichung für $n$ gilt, dass sie auch für $n+1$ gelten muss. Dazu setzen wir anstelle von $n$ ein $n+1$ in die Gleichung ein. Wir behaupten also, dass folgende Gleichung gilt:
$$
\sum\limits_{k=1}^{n+1}k=\dfrac{(n+1)((n+1)+1)}{2}
$$
*Schritt 3: Induktionsschritt*
Um zu beweisen, dass diese Behauptung stimmt, müssen wir eine der beiden Seiten der Gleichungen so umformen, dass die andere Seite daraus ersichtlich wird. Das erreichen wir indem wir die **Induktionsvoraussetzung** in die Gleichung einsetzen.

Üblicherweise ist das Umformen einer Summe einfacher, da wir diese einfach „auseinanderziehen“ können:
$$
\sum\limits_{k=1}^{n+1}k=\sum\limits_{k=1}^{n}k+(n+1)
$$
Nun können wir $\sum\limits_{k=1}^{n}k$ einfach durch die Induktionsvoraussetzung ersetzen, da wir bereits gezeigt haben, dass für diesen Fall die Behauptung erfüllt ist. Daraus ergibt sich:
$$
\begin{align}
&\dfrac{n(n+1)}{2}+(n+1)\\
=&\dfrac{n(n+1)+(n+1)}{2}\\
=&\dfrac{(n+1)(n(n+1)+1)}{2}\\
&\tag*{$\blacksquare$}
\end{align}
$$
Durch die Umformung sehen wir, dass die Induktionsbehauptung stimmt. Damit ist die Behauptung bewiesen.