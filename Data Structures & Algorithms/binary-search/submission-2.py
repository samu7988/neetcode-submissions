class Solution:
    def search(self, nums: list[int], target: int) -> int:
        
        high = len(nums) - 1                             # int high = nums.size() - 1
        low = 0                                          # int low = 0
        mid = 0                                          # int mid = 0
        
        while low <= high:                               # while(low <= high)
            
            mid = (high + low) // 2                      # mid = (high + low) / 2
            
            if nums[mid] == target:                      # if(nums[mid] == target)
                return mid
            elif nums[mid] < target:                     # else if(nums[mid] < target)
                low = mid + 1                            # low = mid + 1
            else:
                high = mid - 1                           # high = mid - 1
        
        return -1