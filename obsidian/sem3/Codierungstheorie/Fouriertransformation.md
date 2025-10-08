Bei den linearen Funktionen entsteht das Rekonstruktionsproblem: Gegeben seien $x(t_1), x(t_2)$, gesucht sind $\alpha, \beta$ mit $x(t)=\alpha+\beta t$.

**Satz**: Gegeben sei ein stückweise stetiges [[Analoge Signale|Signal]] $x(t)$ mit $\int\limits_{-\infty}^{+\infty}|x(t)|^2<\infty$.
Dann existiert eine Funktion $\hat{x}(w)$ mit
$$
x(t)=\frac{1}{\sqrt{2\pi}}\cdot\left(\int\limits_{-\infty}^{+\infty}\hat{x}(\omega)\cdot e^{i\omega t} d\omega\right)\\
=\frac{1}{\sqrt{2\pi}}\cdot\left(\int\limits_{-\infty}^{+\infty}\hat{x}(\omega)\cdot\cos({\omega t}) d\omega+ i \int\limits_{-\infty}^{+\infty}\hat{x}(\omega)\cdot\sin({\omega t}) d\omega\right)
$$

**Interpretation**: $x(t)$ wird zusammengesetzt aus lauter Funktionen $e^{i\omega t}$ mit dem Gewicht $\dfrac{\hat{x}(\omega)}{\sqrt{2\pi}}$ vorgesehen ist.

**Frage**: Wie können wir diese Gewichte berechnen?
**Antwort**: $\exists A$ mit folgender Formel:
$$
\begin{align}
\hat{x}(\omega)&=\frac{1}{\sqrt{2\pi}}\cdot\int\limits_{-\infty}^{\infty}x(t)\cdot e^{-i\omega t}~dt\\
&=\frac{1}{\sqrt{2\pi}}\cdot\left(\int\limits_{-\infty}^{\infty}x(t)\cdot \cos(\omega t)~dt-i\cdot\int\limits_{-\infty}^{\infty}x(t)\cdot \sin(\omega t)~dt\right)
\end{align}
$$
Diese Funktion $\hat{x}(\omega)$ nennt sich die Fourier-Transformierte von $x(t)$ oder Spektrum von $x(t)$.

**Bemerkungen**:
- Wenn $x(t)$ reell und gerade ist ($x(t)=x(-t)$), so ist auch $\hat{x}(\omega)$ gerade und es gilt: $\hat{x}(\omega)=\dfrac{2}{\sqrt{2\pi}}\cdot\int\limits_0^{\infty}x(t)\cdot\cos(\omega t)~dt$
- Wenn $x(t)$ reel und ungerade ist ($x(t)=-x(-t)$), so ist $\hat{x}(\omega)$ ungerade und es gilt: $\hat{x}(\omega)=-\dfrac{2i}{\sqrt{2\pi}}\cdot\int\limits_{t=0}^{\infty}x(t)\cdot\sin(\omega t)~dt$
- Angenommen, $y(t)$ sei die Verschiebung von $x(t)$ um $a$ Zeiteinheiten, d.h. $y(t)=x(t-a)$. Dann gilt: $\hat{y}(\omega)=\hat{x}(t-a)$

## Beispiel
Gegeben sei der Rechtecksimpuls 