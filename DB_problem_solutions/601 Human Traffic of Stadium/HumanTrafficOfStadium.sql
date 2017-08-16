# Write your MySQL query statement below
SELECT a.*
FROM stadium a, stadium b, stadium c
WHERE a.people>=100 AND b.people>=100 AND c.people>=100
    AND 
        ((a.Id-1=b.Id AND b.Id-1=c.Id) OR
        (b.Id-1=c.Id AND c.Id-1=a.Id) OR
        (c.Id-1=a.Id AND a.Id-1=b.Id))
GROUP BY a.Id;