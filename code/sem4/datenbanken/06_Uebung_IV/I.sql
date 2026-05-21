SELECT e.first_name, e.last_name
FROM employees e
WHERE e.employee_id IN (
    SELECT manager_id FROM employees mgr where manager_id IS NOT NULL
);