Frage: „Warum wird im DWH gerne gegen die Normalformen verstoßen?“
> Weil dadurch eine höhere Performance möglich ist.

Aufgabe: „Nennen Sie min. zwei weitere Dimensionen, bei denen ein Verstoß gegen
Normalform sinnvoll ist.“
> 1. Kunde
> 2. Lieferant

Frage: „Sie sollen ein DWH entwerfen mit extrem schnellen Zugriffzeiten. Welches
Modell (Star oder Snowflake) wählen Sie?“
> Star

Aufgabe: „Bauen Sie ein Starschema für den Vertrieb mit folgenden Inhalten:
Verkaufzeitstempel, Menge, Einzelpreis, MwSt, Produktname, Produktgruppe,
Filiale, Ort, PLZ.“
> Table 1: Zeit
> 	- ZID
> 	- Verkaufszeitstempel
> Table 2: Produkt
> 	- PID
> 	- Produktname
> 	- Produktgruppe
> Table 3: Ort
> 	- OID
> 	- Filiale
> 	- Ort
> 	- PLZ
> Fakt:
> 	- Menge
> 	- Einzelpreis
> 	- MwSt
> 	- ZID
> 	- PID
> 	- OID

Aufgabe: „Schreiben Sie eine SQL Abfrage, welche die Verkaufssumme der jeweiligen
Produktgruppen in den Filialen zwischen 12:00 Uhr und 13:00 Uhr am
18.08.2022 ausgibt.“
```sql
SELECT o.filiale,
       p.produktgruppe,
       SUM(f.menge * f.einzelpreis)                AS umsatz_netto,
       SUM(f.menge * f.einzelpreis * (1 + f.mwst)) AS umsatz_brutto
FROM fakt f
JOIN zeit z    ON f.zid = z.zid
JOIN produkt p ON f.pid = p.pid
JOIN ort o     ON f.oid = o.oid
WHERE z.verkaufszeitstempel >= TIMESTAMP '2022-08-18 12:00:00'
  AND z.verkaufszeitstempel <  TIMESTAMP '2022-08-18 13:00:00'
GROUP BY o.filiale, p.produktgruppe
ORDER BY o.filiale, p.produktgruppe;
```