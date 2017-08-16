# Write your MySQL query statement below
SELECT e.Name
FROM Employee e
WHERE e.Id IN
(SELECT t.ManagerId
FROM Employee t
WHERE t.ManagerId IS NOT NULL
GROUP BY t.ManagerId
HAVING COUNT(t.ManagerId)>=5)