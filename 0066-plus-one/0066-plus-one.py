class Solution:
    def plusOne(self, digits: list[int]) -> list[int]:
        # Start a loop from the last digit (least significant) to the first digit
        for i in range(len(digits) - 1, -1, -1):
            # If the current digit is less than 9, simply increment it by 1 and return the result
            if digits[i] < 9:
                digits[i] += 1
                return digits
            # If the digit is 9, it becomes 0 when 1 is added (carry over)
            digits[i] = 0
            
        # If the loop completes, it means all digits were 9 (e.g., 999 -> 000), 
        # so we prepend 1 to the front of the list to get 1000
        return [1] + digits