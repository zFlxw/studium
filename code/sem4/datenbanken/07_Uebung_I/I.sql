SELECT
    e.first_name, e.last_name
FROM
    hr.employees e
WHERE e.employee_id IN (
      SELECT mgr.manager_id FROM hr.employees mgr WHERE mgr.manager_id IS NOT NULL
)