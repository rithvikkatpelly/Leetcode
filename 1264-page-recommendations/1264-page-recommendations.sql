# Write your MySQL query statement below
SELECT DISTINCT l.page_id AS recommended_page
FROM Likes l
JOIN (
  SELECT user2_id AS friend_id FROM Friendship WHERE user1_id = 1
  UNION
  SELECT user1_id AS friend_id FROM Friendship WHERE user2_id = 1
) friends ON l.user_id = friends.friend_id
WHERE l.page_id NOT IN (
  SELECT page_id FROM Likes WHERE user_id = 1
);