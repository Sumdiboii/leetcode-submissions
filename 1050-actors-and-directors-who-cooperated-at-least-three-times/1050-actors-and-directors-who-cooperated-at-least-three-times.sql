-- 5. Actors and Directors Who Cooperated At Least Three Times (LeetCode 1050)
SELECT distinct
    actor_id, 
    director_id 
FROM 
    ActorDirector 
GROUP BY 
    actor_id, 
    director_id 
HAVING 
    COUNT(*) >= 3;