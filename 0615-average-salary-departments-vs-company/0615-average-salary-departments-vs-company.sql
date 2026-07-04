WITH dept_monthly AS (
  SELECT
    DATE_FORMAT(s.pay_date, '%Y-%m') AS pay_month,
    e.department_id,
    AVG(s.amount) AS dept_avg
  FROM Salary s
  JOIN Employee e ON s.employee_id = e.employee_id
  GROUP BY DATE_FORMAT(s.pay_date, '%Y-%m'), e.department_id
),
company_monthly AS (
  SELECT
    DATE_FORMAT(pay_date, '%Y-%m') AS pay_month,
    AVG(amount) AS company_avg
  FROM Salary
  GROUP BY DATE_FORMAT(pay_date, '%Y-%m')
)
SELECT
  d.pay_month,
  d.department_id,
  CASE
    WHEN d.dept_avg > c.company_avg THEN 'higher'
    WHEN d.dept_avg < c.company_avg THEN 'lower'
    ELSE 'same'
  END AS comparison
FROM dept_monthly d
JOIN company_monthly c ON d.pay_month = c.pay_month
ORDER BY d.pay_month, d.department_id;