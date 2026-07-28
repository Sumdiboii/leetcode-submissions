class Solution:
    # 4. Two Sum II - Input Array Is Sorted (LeetCode 167)
    def twoSum(self, numbers: list[int], target: int) -> list[int]:
        # Initialize two pointers at the start and end of the sorted array
        left = 0
        right = len(numbers) - 1
        
        while left < right:
            current_sum = numbers[left] + numbers[right]
            
            # If the sum matches the target, return the 1-indexed positions
            if current_sum == target:
                return [left + 1, right + 1]
            # If the sum is too small, move the left pointer up to increase the sum
            elif current_sum < target:
                left += 1
            # If the sum is too large, move the right pointer down to decrease the sum
            else:
                right -= 1
                
        return []