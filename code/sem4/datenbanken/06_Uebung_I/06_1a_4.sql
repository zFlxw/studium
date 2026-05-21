SELECT first_name || ' ' || last_name as name, employee_id - manager_id as diff from hr.employees
where last_name LIKE 'Baida' or last_name Like 'Geoni' or last_name Like 'Matos'
ORDER BY diff;