Aufgabe: „Nennen Sie min. 5 Hersteller von ETL Tools und für welchen Einsatzzweck diese
besonders geeignet sind.“
> Unnötige Frage

Frage: „Welche Datenbereinigungen sind aus einer Produktionsmaschine denkbar
deren Produktionslogs in ein DWH transformiert werden sollen?“
> 1. Rohdaten zu aggregierten Daten (bspw. durch Umrechnung)
> 2. Datenformate vereinheitlichen
> 3. Temperaturformate vereinheitlichen
> 4. Plausibilitätsprüfung (bspw. Temperatur, Winkel, usw)

Aufgabe: „Nennen Sie 8 problematische Datenquellen für DWH die schwer zu
transformieren sind.“
> 1. Legacy-/Mainframe-Systeme: veraltete Formate (EBCDIC, COBOL-Copybooks), oft fehlende Dokumentation und Know-how-Träger in Rente.
> 2. Excel-Tabellen der Fachabteilungen: manuell gepflegt, freie Formatierung, verbundene Zellen, Strukturänderungen ohne Ankündigung.
> 3. Unstrukturierte Texte wie E-Mails, Word-Dokumente oder PDFs: Die Informationen müssen erst extrahiert werden.
> 4. Gescannte Papierdokumente: erfordern OCR mit entsprechenden Erkennungsfehlern.
> 5. Externe Daten von Partnern oder Marktdatenanbietern: abweichende Schlüssel, Formate werden ohne Absprache geändert, Qualität ist nicht kontrollierbar.
> 6. Webseiten (Scraping) und Social Media: instabile Struktur, Umgangssprache, Ironie, rechtliche Einschränkungen.
> 7. Sensor- und IoT-Datenströme: sehr hohes Volumen, Echtzeitanforderung, Lücken und Rauschen.
> 8. SaaS-APIs (z. B. CRM-Systeme): Abfragelimits, Versionswechsel der Schnittstelle, verschachteltes JSON.

Frage: „Welchen maximalen Laufzeit darf ein ETL-Prozess haben?“
> Er muss kürzer sein als das Ladeintervall, also bevor der nächste ETL-Prozess startet.