class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>>v;
       map<string,vector<string>>mp;
       string n_str;

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
