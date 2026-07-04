# Write your MySQL query statement below
SELECT employee_id
FROM Employees
WHERE employee_id != 1
  AND (
    -- Level 1: Direct reports to head
    manager_id = 1

    OR

    -- Level 2: Reports to a direct report of head
    manager_id IN (
      SELECT employee_id
      FROM Employees
      WHERE manager_id = 1
    )

    OR

    -- Level 3: Reports to a level-2 employee
    manager_id IN (
      SELECT employee_id
      FROM Employees
      WHERE manager_id IN (
        SELECT employee_id
        FROM Employees
        WHERE manager_id = 1
      )
    )
  );