DROP TABLE IF EXISTS uni.hoeren;
DROP TABLE IF EXISTS uni.voraussetzen;
DROP TABLE IF EXISTS uni.pruefen;
DROP TABLE IF EXISTS uni.Vorlesungen;
DROP TABLE IF EXISTS uni.Studenten;
DROP TABLE IF EXISTS uni.Assistenten;
DROP TABLE IF EXISTS uni.Professoren;

CREATE TABLE uni.Professoren(
    PersNr NUMBER PRIMARY KEY,
    Name VARCHAR2(200) NOT NULL,
    Rang VARCHAR2(5) CHECK(Rang='C2' OR Rang='C3' or Rang='C4') NOT NULL,
    Raum NUMBER(3) UNIQUE NOT NULL
);

CREATE TABLE uni.Studenten(
    MatrNr NUMBER PRIMARY KEY,
    Name VARCHAR2(200) NOT NULL,
    Semester NUMBER NOT NULL
);

CREATE TABLE uni.Vorlesungen(
    VorlNr NUMBER PRIMARY KEY,
    Titel VARCHAR2(200) NOT NULL,
    SWS NUMBER NOT NULL,
    GelesenVon NUMBER REFERENCES uni.Professoren(PersNr) NOT NULL
);

CREATE TABLE uni.Hoeren(
    MatrNr NUMBER REFERENCES uni.Studenten(MatrNr) NOT NULL,
    VorlNr NUMBER REFERENCES uni.Vorlesungen(VorlNr) NOT NULL,
    PRIMARY KEY (MatrNr, VorlNr)
);

CREATE TABLE uni.Voraussetzen(
    Vorgaenger NUMBER REFERENCES uni.Vorlesungen(VorlNr) NOT NULL,
    Nachfolger NUMBER REFERENCES uni.Vorlesungen(VorlNr) NOT NULL,
    PRIMARY KEY (Vorgaenger, Nachfolger)
);

CREATE TABLE uni.Assistenten(
    PersNr NUMBER PRIMARY KEY,
    Name VARCHAR2(200) NOT NULL,
    Fachgebiet VARCHAR2(200) NOT NULL,
    Boss NUMBER REFERENCES uni.Professoren(PersNr) NOT NULL
);

CREATE TABLE uni.Pruefen(
    MatrNr NUMBER REFERENCES uni.Studenten(MatrNr) NOT NULL,
    VorlNr NUMBER REFERENCES uni.Vorlesungen(VorlNr) NOT NULL,
    PersNr NUMBER REFERENCES uni.Professoren(PersNr) NOT NULL,
    Note NUMBER(2,1) NOT NULL CHECK(Note>=0.7 AND Note<=5.0),
    PRIMARY KEY (MatrNr, VorlNr)
);