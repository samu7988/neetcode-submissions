class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        mp = {}                                          # unordered_map<int,int> mp
        v = []                                            # vector<int> v
        
        for i in range(len(nums)):                       # for(int i = 0; i < nums.size(); i++)
            rem = target - nums[i]                       # int rem = target - nums[i]
            
            if rem in mp:                                # if(mp.find(rem) != mp.end())
                v.append(mp[rem])                        # v.push_back(mp[rem])
                v.append(i)                              # v.push_back(i)
                break
            
            mp[nums[i]] = i                              # mp[nums[i]] = i (future use)
        
        return v