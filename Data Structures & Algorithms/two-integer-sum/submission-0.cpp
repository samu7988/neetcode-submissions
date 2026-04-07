class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int,int>mp;
        vector<int>res;

        for(int i=0; i < nums.size(); i++)
        {
            mp[nums[i]] = i;
        }
        for(int i = 0 ; i < nums.size(); i++)
        {
            int rem = target - nums[i];
            if(mp.find(rem) != mp.end() && (i != mp[rem]))
            {
                res.push_back(i);
                res.push_back(mp[rem]);
                break;
            }
        }
        return res;
    }
};
