# Write your MySQL query statement below
WITH employee_counts AS (
    SELECT 
        project_id,
        COUNT(employee_id) AS emp_count
    FROM Project
    GROUP BY project_id
)
SELECT project_id
FROM employee_counts
WHERE emp_count = (SELECT MAX(emp_count) FROM employee_counts)