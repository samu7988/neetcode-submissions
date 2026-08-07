class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        int rem = 0;
        vector<int>v;
        for(int i = 0 ; i < nums.size(); i++)
        {   
            rem =  target - nums[i];
            if(mp.find(rem) != mp.end())
            {
                v.push_back(mp[rem]);
                v.push_back(i);
                break;
            }
            mp[nums[i]] = i;
        }
        return v;
    }

};
