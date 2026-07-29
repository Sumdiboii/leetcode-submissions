class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        candidate = None
        votes = 0

        for n in nums: 
            if(votes == 0):
                candidate = n

            if(candidate == n):
                votes += 1

            else: 
                votes -= 1

        return candidate