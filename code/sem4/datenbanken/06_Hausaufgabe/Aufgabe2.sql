CREATE VIEW AVG_GEHALT AS 
SELECT AVG(salary) avg_sal FROM employees;

SELECT 
    a.avg_sal, 
    SUM(case when e.salary > 10000 then 1 else 0 end) cnt_emp_gt_10k,
    SUM(case when e.salary > a.avg_sal then 1 else 0 end) cnt_emp_gt_10k
FROM hr.employees e
CROSS JOIN AVG_GEHALT a
GROUP BY a.avg_sal;