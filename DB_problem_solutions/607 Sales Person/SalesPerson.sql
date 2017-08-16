# Write your MySQL query statement below
SELECT p.name
FROM salesperson p
WHERE p.name NOT IN
(SELECT s.name
FROM orders o JOIN salesperson s ON (o.sales_id=s.sales_id)
              JOIN company c ON (o.com_id=c.com_id)
WHERE c.name='RED')