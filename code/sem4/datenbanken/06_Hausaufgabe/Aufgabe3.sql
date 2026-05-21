SELECT
    e.employee_id,
    FLOOR(LEAST((TRUNC(MONTHS_BETWEEN(SYSDATE, e.hire_date))*0.025*e.salary)+10000, 3*j.MAX_SALARY)/1000)*1000
FROM
    hr.employees e
INNER JOIN
    hr.jobs j
ON 
    j.job_id = e.job_id