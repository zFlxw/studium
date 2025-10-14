Der Begriff „Laufzeit“ ist in der Informatik zweideutig definiert. Je nach Kontext meint man damit:
1) Die Dauer, die ein Algorithmus oder Programm zur Vollendung einer Aufgabe benötigt 
2) Die gesamte Lebensdauer eines Programms während der Ausführung

Letzteres ist relativ selbsterklärend und benötigt keine weitere Erklärung. Alle weiteren Punkte in diesem Dokument beziehen sich auf die Laufzeit als Dauer der Ausführung.
# Laufzeitanalyse
*Warum ist die Analyse eines Algorithmus wichtig?* Die Antwort darauf ist eigentlich recht simpel: Durch eine Analyse eines [[Algorithmen und Datenstrukturen#Algorithmus|Algorithmus]], kann die Performance, also in diesem Fall insbesondere die Laufzeit und der Speicherverbrauch eines Algorithmus vorhergesagt werden. Außerdem lässt sich die Performance von Algorithmen somit vergleichen, sodass man eindeutig sagen kann, welcher Algorithmus besser für eine bestimmte Aufgabe geeignet ist.

„Und wie bestimmt man die Laufzeit eines Algorithmus nun?“. Dazu gibt es verschiedene Ansätze, welche mehr oder weniger gut geeignet sind. 
## Empirischer Ansatz
Eine Möglichkeit ist, den Algorithmus in einer beliebigen Programmiersprache zu implementieren und die Ausführungszeit bei verschiedenen Eingabegrößen zu messen. Das wäre der **empirische Ansatz**.

Das Problem bei diesem Vorgehen ist, dass es viele äußere Einflussfaktoren gibt, die das Messergebnis beeinträchtigen können. Dazu zählen unter anderem:
- Aktive Hintergrundprozesse (des Betriebssystems)
- Verwendete Hardware
- Verwendete Programmiersprache

All diese Faktoren beeinflussen die Laufzeit maßgeblich, ohne dass der Algorithmus selbst etwas damit zutun hat.
## Mathematischer Ansatz
Aus diesem Grund gibt es noch einen zweiten Ansatz, mit dem die Laufzeit eines Algorithmus bestimmt werden kann - den **mathematischen Ansatz**.

Das Vorgehen hierbei ist an sich ebenfalls recht simpel: Jede Operation, die im Algorithmus durchgeführt wird, benötigt eine bestimmte Laufzeit und einen bestimmten Speicherplatz. Die Gesamtheit dieser „Teillaufzeiten“ bezeichnet man als **Kosten** $T(N)$. Da diese Kosten - wie auch beim [[#Empirischer Ansatz|empirischen Ansatz]] - abhängig von der Hardware sind, betrachten wir die Kosten nicht in Zeiteinheiten, sondern einfach nur als Anzahl der zu erledigenden Operationen.

Es ist aber nicht immer (ohne Aufwand) möglich die Summe aller Operationen zu bestimmen, die ein Algorithmus durchführt. Das ist aber auch nicht nötig, da bei großen Eingabewerten eine **ungefähre Annäherung** der Laufzeit ausreichend ist. Daher gibt es verschiedene **Notationen**, die eine solche Annäherung beschreiben.
# Tilde-Notation
Die Tilde-Notation beschreibt eine **ungefähre Approximation** an die tatsächliche Laufzeit eines Algorithmus. Um die Tilde-Notation eines Algorithmus zu bestimmen, benötigen wir die **exakte Laufzeit** als Funktion $T(N)$, wobei $N$ die Größe der Eingabe darstellt. Bei dieser Funktion betrachten wir nun lediglich den höchstwertigen Term, also den Term, bei dem $N$ den größten Exponenten hat.

**Beispiel.** Wir nehmen als Beispiel einen Algorithmus an, dessen Kosten als Funktion
$$
T(N) = \frac{1}{6}N^3+4N^2+6N+5
$$
dargestellt wird. In **Tilde-Notation** wären die Kosten des Algorithmus also
$$
D(N)=~\sim\frac{1}{6}N^3
$$
(die Funktion heißt hier $D(N)$, da $T(N)$ bereits für die exakte Laufzeit vergeben wurde). Wir berechnen nun die exakte und die ungefähre Laufzeit beispielsweise für eine Eingabegröße $N=10$ Elemente:
$$
\begin{align}
T(10)&=\frac{1}{6}\cdot10^3+4\cdot10^2+6\cdot10+5=\frac{1895}{3}=632 \\

D(10)&=~\sim\frac{1}{6}\cdot10^3=\frac{500}{3}=167
\end{align}
$$
Wir sehen, dass die Abweichung der Annährung für einen kleinen Eingabewert recht groß ist, daher betrachten wir nachfolgend, wie sich die Annährung für große Eingabewerte verhält. Da sich große Zahlen schlecht zum Rechnen eignen, schauen wir uns an, wie der Funktionsgraph der Funktion der exakten Laufzeit und der Graph der Annährung aufeinander verläuft.
![[Pasted image 20250102212630.png]]
*Hinweis*: Beide Achsen sind logarithmisch skaliert.

Der rote Funktionsgraph gehört in dieser Abbildung zur Funktion der **exakten Laufzeit**. Der blaue Funktionsgraph beschreibt die **Approximation** durch die Tilde-Notation. Wir sehen also, dass mit steigender Eingabegröße die Abweichung der Annährung vom tatsächlichen Wert immer weiter sinkt und nahezu gegen $0$ geht.

Die formale Definition für dieses Verhalten lautet:
$$
\lim_{N\rightarrow\infty}\frac{T(N)}{D(N)}=1
$$

# Big-Oh Notation
Neben der asymptotischen Annährung können wir aber auch **Schranken** bestimmen. Hierzu gibt es drei Notationen:
- $\Omega$-Notation (untere Schranke, also bestmögliche Laufzeit/Speichernutzung)
- $O$-Notation (obere Schranke, also schlechteste Laufzeit/Speichernutzung)
- $\Theta$-Notation (asymptotische Annährung, also durchschnittliche Laufzeit/Speichernutzung)

Diese Notation ist allerdings etwas schwammig; oft wird die Laufzeit einfach nur als $O(N)$ angegeben und zusätzlich angegeben, ob es sich um den „Best Case“, „Average Case“ oder „Worst Case“ handelt. Wenn nichts angegeben ist, meint $O(N)$ oft auch den „Average Case“, welcher eigentlich mit $\Theta(N$) notiert ist.

*Und wie bestimmt man die obere Schranke in $O$-Notation nun?* Im Endeffekt genauso wie die wir die asymptotische Annährung in der [[#Tilde-Notation]] bestimmen, nur dass hier nun der Koeffizient (also der Vorfaktor) des leitenden Terms vernachlässigt wird.

**Beispiel.** Betrachten wir also einen Algorithmus mit der Laufzeitfunktion
$$
T(N)=5N^2+4N+6
$$
Die **obere Schranke** in $O$-Notation lautet dann
$$
O(T(N))=O(N^2)
$$
Das heißt also konkret, dass der Algorithmus **maximal** $N^2$ Operationen durchführt, tendenziell aber auch weniger Schritte benötigen kann.

**Beispiel.** Was ist aber nun, wenn wir keine Laufzeitfunktion, sondern einen (Pseudo-)Code gegeben haben? Dazu nehmen wir folgende Implementierung eines Algorithmus als Beispiel:
```c
int sum(int array[], int n) {
	int s = 0;
	for (int i = 0; i < n; i++) {
		s += array[i];
	}

	return s;
}
```
Im ersten Schritt ist es wichtig zu verstehen, **was** der Code überhaupt macht. In diesem Fall ist das recht simpel, wir haben eine Funktion gegeben, die die Summe aller Integer in einem Array bildet.

Nun weisen wir jeder - wie beim [[#Mathematischer Ansatz|mathematischen Ansatz]] vorgesehen - jeder Operation einen bestimmten Kostenfaktor zu. Zunächst wird eine Variable vom Typ `int` angelegt und initialisiert. Das ist statische Operation, die unabhängig von der Größe der eingegebenen Daten ist, weswegen wir ihr den Kostenfaktor $1$ zuordnen (also ist die obere Schranke für diese Operation $O(1)$).

Im nächsten Schritt wird es etwas komplizierter. Wir definieren eine Schleife, die abhängig vom Input `n`-mal über ein Array iteriert. Das bedeutet also, der Inhalt der Schleife wird `n` mal ausgeführt. Da der Inhalt der Schleife lediglich aus einer statischen (von der Eingabegröße unabhängigen) Operation besteht, betragen die Kosten der gesamten Schleife $O(N)$. **Wichtig:** Wären in der Schleife weitere Operationen, die von den Eingabewerten abhängig sind, vorhanden oder gäbe es Abbruchbedingungen innerhalb der Schleife, würde das die Laufzeit beeinflussen.

Das `return`-Statement ist ebenfalls ein statischer Aufruf und hat somit Kosten von $O(1)$. Addieren wir diese Kosten nun, kommen wir auf Gesamtkosten von
$$
T(N)=1+N+1=N+2
$$
Das bedeutet, die Gesamtkosten dieses Algorithmus betragen $O(N)$, da wir lediglich den Term höchster Ordnung betrachten.
# Komplexitätsklassen
Oft passiert es, dass mehrere Algorithmen einen ähnlichen oder sogar den gleichen Kostenaufwand besitzen. Gruppiert man diese Algorithmen nach ihren Kosten, bilden sich dadurch die sogenannten **Komplexitätsklassen**. Häufig nutzt man zur Beschreibung dieser die [[#Big-Oh Notation]].

Es wäre unmöglich sich jede einzelne Komplexitätsklasse auf der Welt zu merken (und es wäre auch nicht zielführend), aber es gibt ein paar Komplexitätsklassen, die man kennen sollte, um einschätzen zu können, wie kostenaufwändig ein Algorithmus ist. Folgende Grafik zeigt die wichtigsten Komplexitätsklassen und ihr Wachstumsverhalten recht anschaulich:
![[Pasted image 20250103173433.png|center]]
Quelle: https://javachallengers.com/wp-content/uploads/2023/01/Screenshot-2023-01-30-at-13.27.39.png

Anhand dieser Tabelle lässt sich ebenfalls erkennen, warum es wichtig ist eine möglichst niedrige Laufzeitkomplexität bei einem Algorithmus zu erzielen:
![[Pasted image 20250103174601.png]]
Quelle: Kleinberg, J. & Tardos, E. (2005). *Algorithm Design*, S. 34