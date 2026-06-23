# Write your MySQL query statement below
WITH points AS (
    SELECT first_player AS player_id, first_score AS score FROM Matches
    UNION ALL
    SELECT second_player AS player_id, second_score AS score FROM Matches
),
totals AS (
    SELECT 
        p.player_id, 
        p.group_id, 
        COALESCE(SUM(pt.score), 0) AS total_points
    FROM Players p
    LEFT JOIN points pt ON p.player_id = pt.player_id
    GROUP BY p.player_id, p.group_id
),
ranked AS (
    SELECT 
        group_id,
        player_id,
        ROW_NUMBER() OVER (
            PARTITION BY group_id 
            ORDER BY total_points DESC, player_id ASC
        ) AS rn
    FROM totals
)
SELECT group_id, player_id
FROM ranked
WHERE rn = 1