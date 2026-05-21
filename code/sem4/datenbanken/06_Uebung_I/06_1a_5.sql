SELECT employee_id, first_name || ' ' || last_name as name from hr.employees
WHERE manager_id == 102 or manager_id == 103;