-- 3. Classes With at Least 5 Students (LeetCode 596)
SELECT 
    class 
FROM 
    Courses 
GROUP BY 
    class 
HAVING 
    COUNT(student) >= 5;