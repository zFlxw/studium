SELECT first_name || ' ' || last_name as name, phone_number from hr.employees
WHERE salary >= 15000 OR commission_pct >= 35
ORDER BY hire_date
ASC;