**Frage:** „In einer Versicherung soll ein OLAP aufgebaut werden. Dabei soll analysiert werden, welche Streuung der Zeitverzögerung zwischen Datenstand und Datenmeldung liegen. Welche Form der Temporealisierung empfehlen Sie und warum?“
> 2 D sollte passen, da die Aktualisierungszeit vermutlich irrelevant ist.

**Frage:** „Ein Textilhandel hat seine Produktgruppen neu sortiert. Dies soll in Ihrem OLAP System nachgepflegt werden und dabei die alte Struktur für Bestandsdaten erhalten bleiben. Begründen Sie Ihr Vorgehen.“
> Einfach, da alte und neue Zuordnung je einen Gültigkeitszeitraum brauchen.

**Frage:** „Entwerfen Sie eine Faktentabelle für Produkte mit Umsatz und Tagesbezug. Wie können sie diese Umsätze Tagesgenau Temporealisieren?“
> Einfach, da der Gültigkeitszeitraum genau ein Tag ist.

**Frage**: „Entwerfen Sie eine Dimension Filiale in der die Filiale-Ident unveränderlich aber der Name -tagesgenau temporealisiert ist. Verbinden Sie Filialen und Fakten aus Aufgabe zuvor miteinander.“
> Spalten:
> 	- filiale_id
> 	- name
> 	- name_gueltig_von
> 	- name_gueltig_bis

**Aufgabe:** „Erstellen Sie eine SQL Abfrage, bei der aus der der eben entworfenen Tabelle der Filialname im Jahr 2019 ermittelt werden soll.“
```sql
SELECT filiale_id, name, name_gueltig_von, name_gueltig_bis
FROM   dim_filiale
WHERE  name_gueltig_von <= DATE '2019-12-31'
  AND  name_gueltig_bis >= DATE '2019-01-01';
```
