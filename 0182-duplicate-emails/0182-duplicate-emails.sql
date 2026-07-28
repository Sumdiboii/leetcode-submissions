-- 2. Duplicate Emails (LeetCode 182)
SELECT 
    email 
FROM 
    Person 
GROUP BY 
    email 
HAVING 
    COUNT(email) > 1;