-- 3. Replace Employee ID With The Unique Identifier (LeetCode 1378)
SELECT 
    EmployeeUNI.unique_id, 
    Employees.name
FROM 
    Employees
LEFT JOIN 
    EmployeeUNI ON Employees.id = EmployeeUNI.id;