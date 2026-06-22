# Write your MySQL query statement below
SELECT s.student_id, s.student_name
FROM Student s
WHERE s.student_id IN (
    SELECT student_id FROM Exam
)
AND s.student_id NOT IN (
    SELECT student_id
    FROM Exam e
    WHERE e.score = (SELECT MAX(score) FROM Exam WHERE exam_id = e.exam_id)
       OR e.score = (SELECT MIN(score) FROM Exam WHERE exam_id = e.exam_id)
)
ORDER BY s.student_id