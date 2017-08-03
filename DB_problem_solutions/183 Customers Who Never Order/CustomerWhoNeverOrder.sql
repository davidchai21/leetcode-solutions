# Write your MySQL query statement below
SELECT name AS Customers
FROM Customers
WHERE Id NOT IN (SELECT DISTINCT CustomerID FROM Orders);