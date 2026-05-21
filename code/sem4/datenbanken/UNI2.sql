DROP TABLE IF EXISTS uni.hoeren;
DROP TABLE IF EXISTS uni.voraussetzen;
DROP TABLE IF EXISTS uni.pruefen;
DROP TABLE IF EXISTS uni.Vorlesungen;
DROP TABLE IF EXISTS uni.Studenten;
DROP TABLE IF EXISTS uni.Assistenten;
DROP TABLE IF EXISTS uni.Professoren;

CREATE TABLE uni.Professoren(
PersNr NUMBER(12) PRIMARY KEY, 
Name VARCHAR2(100) NOT NULL,
Rang NUMBER (2) CHECK(Rang = 'C2' OR Rang = 'C3' OR Rang = 'C4') NOT NULL, 
Raum NUMBER (8) UNIQUE
);

CREATE TABLE uni.Studenten(
MatrNr Number(12) PRIMARY KEY,
Name VARCHAR(100) NOT NULL,
Semester NUMBER(12)
);

CREATE TABLE uni.Vorlesungen(
VorlNr NUMBER PRIMARY KEY REFERENCES uni.Vorlesungen(VorlNr),
Titel VARCHAR2(100) NOT NULL,
SWS NUMBER,
gelesen_von NUMBER REFERENCES uni.Professoren(PersNr)
);

CREATE TABLE uni.hoeren(
MatrNr NUMBER NOT NULL REFERENCES uni.Studenten(MatrNr),
VorlNr NUMBER NOT NULL REFERENCES uni.Vorlesungen(VorlNr),
PRIMARY KEY (MatrNr, VorlNr)
);

CREATE TABLE uni.voraussetzen(
Vorgaenger NUMBER NOT NULL,
Nachfolger NUMBER NOT NULL,
PRIMARY KEY (Vorgaenger, Nachfolger)
);

CREATE TABLE uni.Assistenten(
PerslNr NUMBER PRIMARY KEY,
Name VARCHAR2(100) NOT NULL,
Fachgebiet VARCHAR2(100),
Boss NUMBER REFERENCES uni.Professoren(PersNr)
);

CREATE TABLE uni.pruefen(
MatrNr NUMBER NOT NULL REFERENCES uni.Studenten(MatrNr),
VorlNr NUMBER NOT NULL REFERENCES uni.Vorlesungen(VorlNr),
PersNr NUMBER NOT NULL REFERENCES uni.Professoren(PersNr),
Note NUMBER(2,1) CHECK (Note >= 0.7 AND Note <=5.0),
CONSTRAINT pruefen_pk PRIMARY KEY (MatrNr, VorlNr)
);