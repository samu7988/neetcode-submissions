class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        
        left = 0                                         # int left = 0
        right = len(nums) - 1                            # int right = nums.size() - 1
        
        while left <= right:                             # while(left <= right)
            
            total = nums[left] + nums[right]             # int sum = nums[left] + nums[right]
            
            if total == target:                          # if(sum == target)
                return [left + 1, right + 1]             # return {left+1, right+1}
            elif total < target:                         # else if(sum < target)
                left += 1                                # left++
            else:
                right -= 1                               # right--
        
        return []                                        # return {}