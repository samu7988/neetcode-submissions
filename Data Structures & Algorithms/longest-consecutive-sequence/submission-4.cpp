class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>mp;
        int max_len = 0;
        int cnt = 0;

        for(int i = 0 ; i < nums.size();i++)
        {
          mp[nums[i]]++;
        }
        for(int i = 0 ; i < nums.size(); i++)
        {
          cnt = 0;
          if(mp.find(nums[i]-1) == mp.end())
          {
            while(mp.find(nums[i] + cnt) != mp.end())
            {
              cnt++;
            }
            max_len = max(cnt,max_len);
          }
        }
        return max_len;
    }
};
