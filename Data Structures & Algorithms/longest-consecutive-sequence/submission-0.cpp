class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>mp;
          int cnt = 0;
          int longest = 0;

        for(int i = 0 ; i < nums.size(); i++)
        {
          mp[nums[i]]++;
        }
        for(int i = 0; i < nums.size(); i++)
        {
          if(mp.find(nums[i]-1) == mp.end())
          {
               while(mp.find(nums[i] + cnt) != mp.end())
               {
                    cnt++;
               }
               longest = max(longest,cnt);
               cnt = 1;
          }

        }
        return longest;
    }
};
