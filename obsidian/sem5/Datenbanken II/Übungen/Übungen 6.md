**Frage**: „Sie sollen ein OLAP System konzipieren, um die Konzernumsätze eines Handelskonzerns mit 1.000 Filialen Weltweit und einem Warenangebot von 1.000.000 unterschiedlicher Produkten auszuwerten. Welches logische Datenmodell wählen Sie und warum?“
> HOLAP oder ROLAP, kein Data Lake, weil die Daten ausgewertet werden sollen. Tendenz zu HOLAP, da hohe Geschwindigkeit bei Aggregaten.

**Frage**: „Die File-Server eines Dax-Konzerns sollen auf verborgene diskriminierende Inhalte hin permanent durchsucht werden. Welches logische Datenmodell wählen Sie und warum?“
> Data Lake, da unstrukturierte Dateien und Suche statt Aggregation.

**Frage**: „Sie erhalten große Excel Dateien von Umsatzzahlen eines Warenhauses. Daraus sollen sie die Anteile von Warengruppen am jeweiligen Tagesumsatz ermitteln. Welches logische Datenmodell wählen Sie und warum?“
> DOLAP, da kleine, lokale Einzelanalysen.