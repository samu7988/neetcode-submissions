class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        vector<pair<int,int>>v;
        vector<int>s;

        for(int i = 0 ; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        for(auto it : mp)
        {
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());

        for(int i = 0 ; i < k; i++)
        {
            s.push_back(v[i].second);
        }
       return s;
    }
};
