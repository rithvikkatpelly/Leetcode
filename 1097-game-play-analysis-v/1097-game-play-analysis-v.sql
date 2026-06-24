# Write your MySQL query statement below
WITH installs AS (
    SELECT 
        player_id,
        MIN(event_date) AS install_dt
    FROM Activity
    GROUP BY player_id
)
SELECT 
    i.install_dt,
    COUNT(DISTINCT i.player_id) AS installs,
    ROUND(
        COUNT(DISTINCT a.player_id) / COUNT(DISTINCT i.player_id), 
        2
    ) AS Day1_retention
FROM installs i
LEFT JOIN Activity a 
    ON i.player_id = a.player_id 
    AND a.event_date = i.install_dt + INTERVAL 1 DAY
GROUP BY i.install_dt