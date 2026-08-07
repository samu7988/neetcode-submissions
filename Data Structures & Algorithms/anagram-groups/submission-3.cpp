class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        string n_str;
        vector<vector<string>>v;
        map<string,vector<string>>mp;

        for(int i = 0 ; i < strs.size(); i++)
        {
          n_str = strs[i];
          sort(n_str.begin(), n_str.end());
          mp[n_str].push_back(strs[i]);
        }
        for(auto it:mp)
        {
          v.push_back(it.second);
        }
        return v;
    }
};
