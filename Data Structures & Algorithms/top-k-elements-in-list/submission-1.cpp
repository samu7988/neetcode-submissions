class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        vector<pair<int,int>>v;
        vector<int>res;

        for(int i = 0 ; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        for(auto it:mp)
        {
            v.push_back({it.second, it.first});
        }
        sort(v.begin(),v.end());    // sort with occurence in asceding order
        reverse(v.begin(), v.end()); // to get max occurence leement from nums 
        for(int i = 0 ; i < k; i++)
        {
            res.push_back(v[i].second);
        }
        return res;
    }
};
