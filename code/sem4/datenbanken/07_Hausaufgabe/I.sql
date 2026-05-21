-- Korrelierte Singlerowabfrage #1
SELECT
    e.last_name
FROM
    hr.employees e
WHERE 'Accountant' = (
    SELECT
        j.job_title
    FROM
        hr.jobs j
    WHERE
        e.job_id = j.job_id
);

-- Korrelierte Singlerowabfrage #2
SELECT
    e.last_name
FROM
    hr.employees e
WHERE 10000 <= (
    SELECT
        j.min_salary
    FROM
        hr.jobs j
    WHERE
        j.job_id = e.job_id
);

-- Inline-Views #1
SELECT * FROM (
    SELECT
        jb.job_title,
        COUNT(*) anz
    FROM
        hr.employees e
    NATURAL JOIN hr.jobs jb
    GROUP BY job_title
) WHERE anz >= 5;


-- Inline-Views #2
SELECT * FROM (
    SELECT
        e.manager_id,
        mgr.last_name,
        COUNT(*) anz
    FROM
        hr.employees e
    INNER JOIN hr.employees mgr ON mgr.employee_id = e.manager_id
    GROUP BY e.manager_id, mgr.last_name
) WHERE anz > 5;

-- Unkorrelierte Abfrage #1
SELECT
    e.first_name,
    e.last_name,
    e.salary
FROM
    hr.employees e
WHERE e.salary >= (
    SELECT AVG(em.salary)
    FROM hr.employees em
);

-- Unkorrelierte Abfrage #2
SELECT
    j.job_title,
    j.min_salary
FROM
    hr.jobs j
WHERE j.min_salary >= (
    SELECT AVG(jb.min_salary)
    FROM hr.jobs jb
);

-- Multi-Row #1
SELECT
    e.first_name,
    e.last_name
FROM
    hr.employees e
WHERE e.job_id IN (
    SELECT j.job_id
    FROM hr.jobs j
    WHERE j.job_title LIKE '%Manager%'
);

SELECT
    e.first_name,
    e.last_name
FROM
    hr.employees e
WHERE e.job_id IN (
    SELECT j.job_id
    FROM hr.jobs j
    WHERE j.job_title LIKE '%Sales%'
);

-- Common Table Expressions (CTE) #1
WITH
    manager_jobs AS (SELECT j.job_id FROM hr.jobs j WHERE j.job_title LIKE '%Manager%')
SELECT
    e.first_name,
    e.last_name
FROM
    hr.employees e
WHERE e.job_id IN (SELECT * FROM manager_jobs);

-- Common Table Expressions (CTE) #2
WITH
    well_payed AS (SELECT j.job_id FROM hr.jobs j WHERE j.min_salary >= 10000)
SELECT
    e.first_name,
    e.last_name,
    e.salary
FROM
    hr.employees e
WHERE e.job_id IN (SELECT * FROM well_payed);






















