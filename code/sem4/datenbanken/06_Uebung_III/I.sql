SELECT d.department_name, NVL2(mgr.employee_id, mgr.first_name || ' ' || mgr.last_name, 'N/A') manager_name, l.postal_code plz, NVL(SUM(e.salary), 0) sum
FROM hr.departments d
JOIN hr.locations l
    ON d.location_id = l.location_id AND l.postal_code IS NOT NULL
LEFT JOIN hr.employees mgr
    ON mgr.employee_id = d.manager_id
LEFT JOIN hr.employees e
    ON e.department_id = d.department_id AND e.employee_id != mgr.employee_id
GROUP BY d.department_name, manager_name, plz;