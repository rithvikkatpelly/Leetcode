# Write your MySQL query statement below
WITH seller_totals AS (
    SELECT 
        seller_id,
        SUM(price) AS total_sales
    FROM Sales
    GROUP BY seller_id
)
SELECT seller_id
FROM seller_totals
WHERE total_sales = (SELECT MAX(total_sales) FROM seller_totals)