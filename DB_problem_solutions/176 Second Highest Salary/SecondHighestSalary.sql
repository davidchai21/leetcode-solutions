# Write your MySQL query statement below
SELECT (CASE WHEN (SELECT COUNT(DISTINCT Salary) FROM Employee)=1 THEN NULL
             ELSE
       (SELECT DISTINCT Salary FROM Employee ORDER BY Salary DESC LIMIT 1 OFFSET 1) END) AS SecondHighestSalary;
