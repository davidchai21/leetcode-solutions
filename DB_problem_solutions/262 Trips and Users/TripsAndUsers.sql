# Write your MySQL query statement below
SELECT t.Request_at AS Day, round(SUM(CASE WHEN t.Status LIKE 'Cancelled_%' THEN 1 ELSE 0 END)/COUNT(*),2) AS 'Cancellation Rate'
FROM Trips t JOIN Users a ON (t.Client_Id=a.Users_Id AND a.Banned='No')
WHERE t.Request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY t.Request_at;