class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int>mp;

        if(s.size() != t.size())
        {
            return false;
        }
        for(int i = 0 ; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        for(int j = 0 ; j < t.size(); j++)
        {
            mp[t[j]]--;
            if(mp[t[j]] == 0)
            {
                mp.erase(t[j]);
            }
        }
        if(mp.empty())
        {
            return true;
        }
        return false;
    }
};
