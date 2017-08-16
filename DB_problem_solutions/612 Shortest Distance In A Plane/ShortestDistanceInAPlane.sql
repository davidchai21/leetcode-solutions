# Write your MySQL query statement below
SELECT ROUND(MIN(SQRT((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y))),2) AS shortest
FROM point_2d a, point_2d b
WHERE NOT (a.x=b.x AND a.y=b.y)