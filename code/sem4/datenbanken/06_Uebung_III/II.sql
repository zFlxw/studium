SELECT e.employee_id FROM hr.employees e
JOIN jobs j
ON
    e.job_id = j.job_id and j.job_title = 'Programmer'
JOIN employees r ON r.first_name = 'Kevin' and r.last_name = 'Mourgos'
WHERE e.salary > r.salary-200