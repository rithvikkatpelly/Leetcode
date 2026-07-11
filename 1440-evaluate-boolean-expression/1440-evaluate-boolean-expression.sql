# Write your MySQL query statement below
SELECT
  e.left_operand,
  e.operator,
  e.right_operand,
  CASE
    WHEN e.operator = '>' AND vl.value >  vr.value THEN 'true'
    WHEN e.operator = '<' AND vl.value <  vr.value THEN 'true'
    WHEN e.operator = '=' AND vl.value =  vr.value THEN 'true'
    ELSE 'false'
  END AS value
FROM Expressions e
JOIN Variables vl ON e.left_operand  = vl.name
JOIN Variables vr ON e.right_operand = vr.name;