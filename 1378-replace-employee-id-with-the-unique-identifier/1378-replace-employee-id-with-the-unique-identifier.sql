# Write your MySQL query statement below

SELECT
    e.unique_id,
    ee.name
FROM Employees ee
LEFT JOIN EmployeeUNI e
ON ee.id = e.id;