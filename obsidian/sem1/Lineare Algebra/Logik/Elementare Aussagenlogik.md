# Definition der Grundbegriffe
- Eine **Aussage** $A$ ist ein Satz der in einem gegebenen Kontext eindeutig wahr $w$ oder falsch $f$ ist.
- Die **Negation** einer Aussage $A$ wird als $\lnot A$ bezeichnet und ist die dann wahr, wenn $A$ falsch ist, bzw. dann falsch, wenn $A$ wahr ist.
- Die **Konjunktion** (Und-Verknüpfung) zwischen zwei Aussagen $A_1, A_2$ wird als $A_1 \land A_2$ geschrieben. Sie ist genau dann wahr, wenn $A_1$ und $A_2$ beide wahr sind.
- Die **Disjunktion** (Oder-Verknüpfung) zwischen zwei Aussagen $A_1, A_2$ wird als $A_1 \lor A_2$ geschrieben. Sie ist genau dann wahr, wenn entweder $A_1$ oder $A_2$ oder beide wahr sind.
- Die **Kontravalenz** (Entweder-Oder-Verknüpfung, auch „Exklusiv-Oder“ genannt) zwischen zwei Aussagen $A_1,A_2$ wird als $A_1\veebar A_2$ geschrieben. Sie ist genau dann wahr, wenn entweder $A_1$ oder $A_2$ wahr ist, nicht aber wenn beide wahr sind.
# Implikation und Äquivalenz
Die **Implikation** von $A$ nach $B$ wird auch „Wenn-Dann-Verknüpfung“ genannt und als $A\Longrightarrow B$ geschrieben. Sie beschreibt, dass immer dann, wenn $A$ wahr ist, auch $B$ wahr sein muss.

Die **Äquivalenz** der Aussagen $A$ und $B$ wird auch „Genau-Wenn-Dann-Verknüpfung“ genannt und als $A \Longleftrightarrow B$ geschrieben. Sie beschreibt, dass genau dann, wenn $A$ wahr ist auch $B$ wahr sein muss und wenn $A$ falsch ist, auch $B$ falsch sein muss.
# Gesetze
Betrachten wir die logischen Ausdrücke $A, B$ und $C$, so gelten die folgenden Gesetze.
## Kommutativgesetze
- $A\land B \Longleftrightarrow B\land A$
- $A \lor B \Longleftrightarrow B\lor A$
## Assoziativgesetze
- $(A\land B)\land C \Longleftrightarrow A \land (B \land C)$
- $(A\lor B)\lor C \Longleftrightarrow A \lor (B \lor C)$
## Distributivgesetze
- $(A \land B) \lor C \Longleftrightarrow (A \lor C) \land (B \lor C)$
- $(A \lor B) \land C \Longleftrightarrow (A \land C) \lor (B \land C)$
## Absorptionsgesetze
- $A \land (A \lor B) \Longleftrightarrow A$
- $A \lor (A \land B) \Longleftrightarrow A$
## De-Morgansche Gesetze
- $\lnot (A\land B) \Longleftrightarrow \lnot A \lor \lnot B$
- $\lnot(A \lor B) \Longleftrightarrow \lnot A \land \lnot B$

Darüber hinaus gelten folgende Regeln:
- **Modus Babara** (Kettenschluss): $(A\rightarrow B)\land (B\rightarrow C) \Longrightarrow (A \rightarrow B)$
- **Modus Ponens** (Abtrennungsregel): $A\land(A\rightarrow B)\Longrightarrow C$
- **Modus Tollens** (Aufhebungsregel): $\lnot A\land (B\rightarrow A)\Longrightarrow \lnot B$
- **Kontraposition** (Umkehrschluss): $(A\longrightarrow B)\Longrightarrow (\lnot B\longrightarrow \lnot A)$
