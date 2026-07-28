class Solution:
    # 5. Fizz Buzz (LeetCode 412)
    def fizzBuzz(self, n: int) -> list[str]:
        result = []
        
        for i in range(1, n + 1):
            divisible_by_3 = (i % 3 == 0)
            divisible_by_5 = (i % 5 == 0)
            
            # Check divisibility by both 3 and 5 first
            if divisible_by_3 and divisible_by_5:
                result.append("FizzBuzz")
            elif divisible_by_3:
                result.append("Fizz")
            elif divisible_by_5:
                result.append("Buzz")
            else:
                result.append(str(i))
                
        return result