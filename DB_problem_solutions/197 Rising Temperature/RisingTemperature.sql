# Write your MySQL query statement below
SELECT a.Id AS Id
FROM Weather a JOIN Weather b ON (DATEDIFF(a.Date,b.Date)=1)
WHERE a.Temperature>b.Temperature;