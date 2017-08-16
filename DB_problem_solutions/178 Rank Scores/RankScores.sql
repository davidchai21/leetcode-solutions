# Write your MySQL query statement below
SELECT a.Score, (SELECT COUNT(DISTINCT Score) FROM Scores b WHERE a.Score<=b.Score) AS Rank
FROM Scores a
ORDER BY Score DESC;