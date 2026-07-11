WITH approved AS (
  SELECT
    DATE_FORMAT(trans_date, '%Y-%m') AS month,
    country,
    COUNT(*) AS approved_count,
    SUM(amount) AS approved_amount
  FROM Transactions
  WHERE state = 'approved'
  GROUP BY DATE_FORMAT(trans_date, '%Y-%m'), country
),
chargebacks AS (
  SELECT
    DATE_FORMAT(c.trans_date, '%Y-%m') AS month,
    t.country,
    COUNT(*) AS chargeback_count,
    SUM(t.amount) AS chargeback_amount
  FROM Chargebacks c
  JOIN Transactions t ON c.trans_id = t.id
  GROUP BY DATE_FORMAT(c.trans_date, '%Y-%m'), t.country
)
-- Rows that exist in approved (with or without chargebacks)
SELECT
  COALESCE(a.month, cb.month) AS month,
  COALESCE(a.country, cb.country) AS country,
  COALESCE(a.approved_count, 0) AS approved_count,
  COALESCE(a.approved_amount, 0) AS approved_amount,
  COALESCE(cb.chargeback_count, 0) AS chargeback_count,
  COALESCE(cb.chargeback_amount, 0) AS chargeback_amount
FROM approved a
LEFT JOIN chargebacks cb
  ON a.month = cb.month AND a.country = cb.country

UNION

-- Rows that exist in chargebacks only (no approved transactions that month)
SELECT
  cb.month,
  cb.country,
  0 AS approved_count,
  0 AS approved_amount,
  cb.chargeback_count,
  cb.chargeback_amount
FROM chargebacks cb
LEFT JOIN approved a
  ON cb.month = a.month AND cb.country = a.country
WHERE a.month IS NULL;