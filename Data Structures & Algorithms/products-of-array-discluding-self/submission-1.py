class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        v = []
        left = 1
        right = 1
        
        for i in range(len(nums)):                       # outer loop
            
            for j in range(i + 1, len(nums)):            # multiply elements to the RIGHT of i
                right *= nums[j]
            
            for j in range(i - 1, -1, -1):               # multiply elements to the LEFT of i
                left *= nums[j]
            
            v.append(right * left)
            left = 1                                      # reset for next i
            right = 1
        
        return v