**Frage:** „Im Monitoring eines DWH wird eine permanente Volllast nur eines Prozessor-Cores angezeigt. Auf welches Probleme weißt dies hin?“
> Datenbank-Konfiguration vermutlich so eingestellt, dass keine Parallelität durchgeführt wird. Bspw. durch „Anzahl maximale Prozessorkerne: 1“.


**Frage**: „Sie sollen ein großes DWH einrichten mit vielen unstrukturierten Daten das gleichzeitig Green-IT ist. Wo liegt das Dilemma?“
> Unstrukturierte Daten können sehr groß und schwer zu komrpimieren sein, wodurch sie auf Dauer viel Speicherplatz einnehmen, obwohl sie evtl gar nicht mehr gebraucht werden. Das benötigt Strom und Speicherkapazitäten. Außerdem benötigen sie einen separaten Transformationsprozess, der ebenfalls rechenaufwändig sind. Diese Rechenleistung fördert indirekt den Verbrauch von Wasser zur Kühlung und den CO₂-Ausstoß. Die Frage ist also: Spart man an Leistung, um den Wasserverbrauch und CO₂-Ausstoß niedriger zu halten oder nimmt man das in Kauf?


**Frage:** „Recherchieren Sie nach Sicherheitsproblemen in großen Analysesystemen die zu
Strafverfahren nach DSGVO führten. Wie hätte sich dies verhindern lassen?“
> 1. Deutsche Wohnen (2019) - speicherten sensible Daten von Mietern über Jahre hinweg, ohne zu prüfen, ob diese rechtmäßig sind und ohne eine Möglichkeit zur Löschung der Daten. Die Berliner Datenschutzbehörde verhängte dafür ein Bußgeld von 14,5 Millionen Euro.
>	Das Problem hätte sich dadurch lösen lassen, wenn von Anfang an ein geeignetes Löschkonzept erarbeitet und implementiert worden wäre.

> 1. H&M (2020) - Es wurden intern detaillierte Profile über Mitarbeiter angelegt, die bis zu 50 Führungskräften zugänglich waren. Durch einen Fehler konnten diese Profile jedoch von allen Mitarbeitern eingesehen werden. Die Hamburger Datenschutzbehörde verhängte ein Bußgeld i. H. v. 35,3 Millionen Euro.
> 	Das Grundproblem ist, dass die Daten in erster Linie gar nicht hätten erhoben werden dürfen.


**Aufgabe:** „Sie werden zu einem Kunden zur Beschleunigung eines OLAP-Systems gerufen. Erstellen Sie einen Arbeitsplan wie Sie vorgehen und welche Punkte Sie sich in welcher Reihenfolge annehmen wollen.“
> 1) Informationsmanagement
> 2) Datenbank Design
> 3) Anwendungsumgebung
> 4) Datenbankzugriff
> 5) Datenbank Konfiguration
> 6) Betriebssystem