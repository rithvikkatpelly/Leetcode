WITH RECURSIVE visit_txn_counts AS (
  SELECT
    v.user_id,
    v.visit_date,
    COUNT(t.transaction_date) AS transactions_count
  FROM Visits v
  LEFT JOIN Transactions t
    ON v.user_id = t.user_id
    AND v.visit_date = t.transaction_date
  GROUP BY v.user_id, v.visit_date
),
max_count AS (
  SELECT MAX(transactions_count) AS max_txn FROM visit_txn_counts
),
all_counts AS (
  SELECT 0 AS n
  UNION ALL
  SELECT n + 1
  FROM all_counts
  JOIN max_count ON n < max_txn
)
SELECT
  a.n AS transactions_count,
  COUNT(v.transactions_count) AS visits_count
FROM all_counts a
LEFT JOIN visit_txn_counts v
  ON a.n = v.transactions_count
GROUP BY a.n
ORDER BY a.n;