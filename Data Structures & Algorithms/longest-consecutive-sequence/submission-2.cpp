class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>mp;
          int cnt = 1;
          int longest = 0;

        for(int i = 0 ; i < nums.size(); i++)
        {
          mp[nums[i]]++;
        }
        for(int i = 0; i < nums.size(); i++)
        {
          if(mp.find(nums[i]-1) == mp.end())                    // if current element is ideal candidate as start of sequence 
          {
               while(mp.find(nums[i] + cnt) != mp.end())     // if num at nums[i] position is ideal candidate to start the sequence with 
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
