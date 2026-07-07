# Write your MySQL query statement below
WITH all_calls AS (
  -- Each call counts for both caller's and callee's country
  SELECT caller_id AS person_id, duration FROM Calls
  UNION ALL
  SELECT callee_id AS person_id, duration FROM Calls
),
country_avg AS (
  SELECT
    c.name AS country,
    AVG(a.duration) AS avg_duration
  FROM all_calls a
  JOIN Person p ON a.person_id = p.id
  JOIN Country c ON LEFT(p.phone_number, 3) = c.country_code
  GROUP BY c.name
)
SELECT country
FROM country_avg
WHERE avg_duration > (SELECT AVG(duration) FROM Calls);
