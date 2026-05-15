class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if (strs.empty()) return "";                       // edge case: empty input
        
        sort(strs.begin(), strs.end());                    // sort lexicographically
        
        string first = strs[0];                            // smallest string
        string last  = strs[strs.size() - 1];              // largest string
        
        string prefix = "";                                // result
        
        int len = min(first.size(), last.size());          // compare up to shorter length
        
        for (int i = 0; i < len; i++)
        {
            if (first[i] != last[i])                       // mismatch found
                break;                                      // stop comparing
            
            prefix += first[i];                            // matching char → add to prefix
        }
        
        return prefix;
    }
};