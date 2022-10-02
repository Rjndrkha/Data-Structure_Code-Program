# Write your MySQL query statement below
SELECT P.lastName, P.firstName, A.city, A.state
FROM Person P LEFT JOIN Address A ON P.personId = A.personId