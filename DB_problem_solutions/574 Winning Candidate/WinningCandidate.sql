# Write your MySQL query statement below
SELECT c.Name
FROM Candidate c JOIN
(SELECT t.CandidateId, COUNT(*) AS n
FROM Vote t
GROUP BY t.CandidateId
ORDER BY n DESC
LIMIT 1 OFFSET 0) AS v
ON c.id=v.CandidateId