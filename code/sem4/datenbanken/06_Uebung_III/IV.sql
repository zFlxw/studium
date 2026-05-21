SELECT j.job_title jt, AVG(e.salary) avg, COUNT(e.job_id) c, (j.min_salary+j.max_salary)/2 mm
FROM hr.employees e
INNER JOIN hr.jobs j
    ON e.job_id = j.job_id
GROUP BY jt, mm
HAVING c >= 2 and avg > mm;