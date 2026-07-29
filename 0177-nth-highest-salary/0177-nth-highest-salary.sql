CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  -- We redefine N to be N - 1 right here
  SET N = N - 1;
  
  RETURN (
      -- Now we just plug that new N into the offset
      SELECT DISTINCT salary
      FROM Employee
      ORDER BY salary DESC
      LIMIT 1 OFFSET N
  );
END