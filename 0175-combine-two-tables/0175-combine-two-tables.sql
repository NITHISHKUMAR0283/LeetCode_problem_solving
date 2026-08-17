# Write your MySQL query statement below
SELECT   Person.firstName , Person.lastName , Address.city , Address.state
FROM Person
lEFT JOIN ADDRESS 
ON Person.personId = Address.personId;