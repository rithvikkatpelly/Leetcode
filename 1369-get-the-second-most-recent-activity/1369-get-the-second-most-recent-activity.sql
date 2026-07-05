# Write your MySQL query statement below
WITH ranked AS (
  SELECT
    username,
    activity,
    startDate,
    endDate,
    ROW_NUMBER() OVER (PARTITION BY username ORDER BY endDate DESC) AS rn,
    COUNT(*)     OVER (PARTITION BY username)                       AS total
  FROM UserActivity
)
SELECT username, activity, startDate, endDate
FROM ranked
WHERE rn = 2        -- second most recent
   OR total = 1     -- only one activity, return it
ORDER BY username;