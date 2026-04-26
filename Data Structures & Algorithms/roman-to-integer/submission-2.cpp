class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;                          // stores final integer result

        // map each roman numeral character to its integer value
        unordered_map<char, int> mp{
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        for(int i = 0; i < s.size(); i++)
        {
            // if current value is LESS than next value → subtractive case
            // e.g. IV=4, IX=9, XL=40, XC=90, CD=400, CM=900
            if(mp[s[i]] < mp[s[i + 1]])
            {
                ans = ans - mp[s[i]];   // subtract current value (e.g. I in IV)
            }
            else
            {
                ans = ans + mp[s[i]];   // normal case → add current value
            }
        }

        return ans;   // return final converted integer
    }
};