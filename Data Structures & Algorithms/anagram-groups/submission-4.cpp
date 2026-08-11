class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        string n_str;                                       // temp copy of current string (for sorting)
        vector<vector<string>> v;                            // final result: groups of anagrams
        map<string, vector<string>> mp;                      // sorted-key → list of original words

        for (int i = 0; i < strs.size(); i++)
        {
            n_str = strs[i];                                 // copy current word (so we don't modify original)
            sort(n_str.begin(), n_str.end());                // sort chars → canonical form for anagrams
            mp[n_str].push_back(strs[i]);                    // group original word under sorted key
        }
        
        for (auto it : mp)                                   // iterate over each group in the map
        {
            v.push_back(it.second);                          // add the vector of anagrams to result
        }
        return v;
    }
};