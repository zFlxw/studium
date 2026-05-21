SELECT DISTINCT e.employee_id
FROM hr.employees e
LEFT JOIN job_history h ON h.employee_id = e.employee_id
WHERE (
    h.employee_id IS NUll
) OR (
    h.employee_id = e.employee_id 
    AND (
        TO_DATE('01.01.2005','dd.mm.yyyy') >= h.start_date
        AND TO_DATE('31.12.2005','dd.mm.yyyy') <= h.end_date
    )
);
