class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        map<string,vector<string>>mp;
        vector<vector<string>>v;

        string n_st;

        for(int i = 0 ; i < s.size(); i++)
        {
            n_st = s[i];

            sort(n_st.begin(), n_st.end());

            mp[n_st].push_back(s[i]);
        }
        for(auto it : mp)
        {
            v.push_back(it.second);
        }
        return v;
    }
};
