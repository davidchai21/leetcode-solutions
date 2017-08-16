# Write your MySQL query statement below
SELECT SUM(e.TIV_2016) AS TIV_2016
FROM insurance e
WHERE e.TIV_2015 IN
    (SELECT a.TIV_2015
        FROM insurance a
        GROUP BY a.TIV_2015
        HAVING COUNT(*)>1)
    AND
     CONCAT(e.LAT,e.LON) IN
    (SELECT CONCAT(b.LAT,b.LON) AS l
      FROM insurance b
      GROUP BY l
      HAVING count(*)=1)