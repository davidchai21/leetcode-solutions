# Write your MySQL query statement below
SELECT d.Name AS Department, e.Name AS Employee, e.Salary AS Salary
FROM Employee e JOIN Department d ON (e.DepartmentId=d.Id)
WHERE 3>(SELECT COUNT(DISTINCT t.Salary)
            FROM Employee t
            WHERE t.Salary>e.Salary
                AND t.DepartmentId=e.DepartmentId);