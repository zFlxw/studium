## Übung
> Sie sind Geldwäschebeauftragter und überwachen die institutsinternen Kontobewegungen. Sie haben eine DB mit allen Kunden der XY-Bank und allen Überweisungen von Kunden der XY-Bank an Kunden der XY-Bank. Wandeln Sie das oben abgebildete und halbfertige logische Schema in ein physisches Schema in Form von SQL um. Überlegen Sie sich sinnvolle Datentypen, Constraints und Kommentare.

![[Pasted image 20260424193303.png]]

```sql
CREATE TABLE Kunde(
	ID NUMBER PRIMARY KEY,
	Name VARCHAR2(200) NOT NULL,
	IBAN VARCHAR2(50) NOT NULL UNIQUE CHECK(length(IBAN)>=12),
	Geschlecht CHAR(1) NOT NULL CHECK(Geschlecht='W' or Geschlecht='M' or Geschlecht='D'),
);

CREATE TABLE Ueberweisung(
	Kennung VARCHAR2 PRIMARY KEY,
	Von NUMBER NOT NULL REFERENCES Kunde(ID),
	Zu NUMBER NOT NULL REFERENCES Kunde(ID),
	Betrag NUMBER NOT NULL CHECK(Betrag>0),
	Datum DATE NOT NULL,
	interner_vermerk VARCHAR2(2000)
	CONSTRAINT von_zu_ck CHECK Von <> Zu,
);

COMMENT ON COLUMN Ueberweisung.Von IS 'Kunde von dem Zahlung ausgeht';
COMMENT ON COLUMN Ueberweisung.Zu IS 'Kunde an dem Zahlung gesendet wird';
```
