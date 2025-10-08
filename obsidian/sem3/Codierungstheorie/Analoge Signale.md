Ein **Signal** (Zeitsignal) $x$ ist eine physikalische Größe (ohne Maßeinheit), die sich als Funktion der Zeit darstellen lässt, also $x = x(t)$.

**Beispiel:** Stromstärke, Feldstärke, Schallwellen, Temperatur.

Diese Signale liegen in der Regel in der Form eines analogen Verlaufs vor, also als zeit- und wertkontinuierliche Funktion.
Aus mathematischer Sicht ist ein zeitkontinuierliches Signal nichts anderes als eine Funktion
$$
x:\mathbb{R}\longrightarrow\mathbb{C}
$$
Ein zeit- und wertkontinuierliches Signal ist eine stetige(!) Funktion
$$
x:\mathbb{R}\longrightarrow\mathbb{C}
$$
Ein Zeitsignal kann also etwa so aussehen
![[Pasted image 20251008102453.png|center]]
## Diskretisierung
Zum Zwecke der Speicherung werden analoge Signale diskretisiert, d. h. diese Signale werden zu gewissen Zeitpunkten $t_k$ gemessen (abgetastet). Dabei wählt man üblicherweise konstante Zeitabstände, d. h. $t_{k+1}=t_k+\Delta t$ mit $\Delta t$ konstant.

Schreibweise: $x(k)=x(t_k)=x(t_0+k\Delta t), k\in\mathbb{Z}$
![[Pasted image 20251008102521.png|center]]
## Problem
Unter welchen Voraussetzungen an das Signal und an die Abtaststelle können wir das kontinuierliche Signal $x(t)$ vollständig (also ohne Informationsverlust) aus seiner Darstellung $x(k), k\in\mathbb{Z}$ wiederherstellen?

Offensichtlich hängt die Antwort von $x$ sowie von der Abtaststelle ab.
Beispiel: $x(t)$ linear, dann reichen sogar zwei Abtastpunkte aus.