# Write your MySQL query statement below
SELECT firstname, lastname, city, state
FROM person left join address
ON person.personID=address.personID;