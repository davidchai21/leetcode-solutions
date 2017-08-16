# Write your MySQL query statement below
SELECT MAX(num) AS num
FROM
(SELECT num, COUNT(num) AS a
FROM number
GROUP BY num) AS t
WHERE a=1;