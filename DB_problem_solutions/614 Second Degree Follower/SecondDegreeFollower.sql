# Write your MySQL query statement below
SELECT f.followee AS follower, COUNT(*) AS num
FROM (SELECT DISTINCT * FROM follow) f
WHERE f.followee IN (SELECT follower FROM follow)
GROUP BY f.followee
ORDER BY f.followee
