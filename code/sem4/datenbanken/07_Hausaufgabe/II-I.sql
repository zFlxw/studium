WITH
    alle_noten AS (
        SELECT
            p.vorlnr,
            COUNT(*) anz
        FROM
            uni.pruefen p
    ),
    durchgefallen AS (
        SELECT
            p.vorlnr,
            COUNT(*) anz
        FROM
            uni.pruefen p
        WHERE p.note > 4.0
        GROUP BY p.vorlnr
        HAVING anz >= (SELECT anz FROM alle_noten an WHERE an.vorlnr = p.vorlnr)
    )
SELECT
    vorlnr,
    'zu hoch' bewertung
FROM durchgefallen;