# Write your MySQL query statement below
SELECT a.Name AS Employee
FROM Employee a JOIN Employee b ON (a.managerID=b.id)
WHERE 
( a.salary>b.salary)