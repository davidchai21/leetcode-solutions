# Write your MySQL query statement below
SELECT d.Name AS Department, Employee.Name AS Employee, Employee.Salary AS Salary
FROM Department d, Employee
WHERE d.Id=Employee.DepartmentId AND Employee.Salary=(SELECT MAX(Salary) FROM Employee e WHERE d.Id=e.DepartmentId)