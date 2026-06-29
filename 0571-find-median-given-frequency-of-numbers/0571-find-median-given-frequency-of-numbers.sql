# Write your MySQL query statement below
SELECT
  ROUND(AVG(num), 1) AS median
FROM (
  SELECT
    num,
    frequency,
    SUM(frequency) OVER (ORDER BY num) AS cum_freq,
    SUM(frequency) OVER () AS total_freq
  FROM Numbers
) t
WHERE cum_freq - frequency <= total_freq / 2.0
  AND cum_freq >= total_freq / 2.0;