## Aufgabe 4.1
Was verstehen wir unter Interprozesskommunikation? 
> Prozesse müssen sich untereinander abstimmen, wenn sie die gleichen Ressourcen nutzen wollen, damit es nicht zu Konflikten/ Race Conditions kommt. Dabei wird vermieden, dass gemeinsame Ressourcen zeitgleich verwendet werden und es erfolgt eine Weiterleitung von Informationen zwischen den Prozessen.

In welchen Fällen ist Interprozesskommunikation durch das Betriebssystem notwendig?
> Immer dann, wenn mehrere Prozesse zeitgleich die gleichen Ressourcen verwenden wollen.

## Aufgabe 4.2
Nennen Sie die Bedingungen, die ein Pattern für wechselseitigen Ausschluss erfüllen
muss!
- Keine zwei Prozesses sind gleichzeitig in kritischen Regionen
- Keine Annahmen über Geschwindigkeit und Anzahl der CPU
- Kein Prozess, der außerhalb der Kritischen Regionen läuft, darf andere Prozesse blockieren
- Kein Prozess soll ewig warten, um in seine kritische Region einzutreten

## Aufgabe 4.3
Beschreiben Sie in einem kurzen Abriss, wie ein Betriebssystem, das Interrupts
ausschalten kann, Semaphoren realisieren könnte?
> Zuerst müssen Interrupts ausgeschaltet werden, danach Semaphoren anlegen (jeweils mit Zähler und Queue) und anschließend Interrupts wieder aktivieren.

