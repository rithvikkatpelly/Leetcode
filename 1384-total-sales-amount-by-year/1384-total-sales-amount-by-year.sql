# Write your MySQL query statement below
WITH years AS (
  SELECT '2018' AS report_year, '2018-01-01' AS year_start, '2018-12-31' AS year_end
  UNION ALL
  SELECT '2019', '2019-01-01', '2019-12-31'
  UNION ALL
  SELECT '2020', '2020-01-01', '2020-12-31'
)
SELECT
  s.product_id,
  p.product_name,
  y.report_year,
  (DATEDIFF(
    LEAST(s.period_end, y.year_end),
    GREATEST(s.period_start, y.year_start)
  ) + 1) * s.average_daily_sales AS total_amount
FROM Sales s
JOIN Product p ON s.product_id = p.product_id
JOIN years y
  ON s.period_start <= y.year_end
  AND s.period_end >= y.year_start
ORDER BY s.product_id, y.report_year;