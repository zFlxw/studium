Frage: „Mit welchen SQL Schlüsselwörtern können händisch Slice und Dice umgesetzt
werden?“
> `WHERE`, `GROUP BY` und `HAVING`.

Frage: „Zu welcher DWH Navigation passt das SQL Schlüsselwort `UNION`?“
> Drill-Down oder Drill-Across?

Frage: „Wieso kann in OLAP Systemen von dem ACID Modell abgewichen werden?“
> In den meisten Fällen bedeutet OLAP rein lesender Zugriff.

Aufgabe: „Zeigen Sie ein Szenario, in dem es zu Multiversionen in einem OLAP System
kommen kann.“
> Bereits geladene Quartalszahlen werden nachträglich korrigiert, danach existieren eine „berichtete“ und eine „korrigierte“ Version.

Frage: „Welche Auswirkungen können Konsistenzprobleme auf die Korrelationsanalyse
haben?“
> Es können Scheinkorrelationen entstehen oder tatsächliche Korrelationen können unentdeckt bleiben.