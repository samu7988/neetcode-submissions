class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;   // char → last seen index
        int left = 0;
        int result = 0;

        for (int right = 0; right < s.size(); right++) {
            // If char was seen AND is inside current window
            if (lastSeen.count(s[right]) && lastSeen[s[right]] >= left) {
                left = lastSeen[s[right]] + 1;  // shrink window past duplicate
            }

            lastSeen[s[right]] = right;                  // update last seen index
            result = max(result, right - left + 1);      // update best result
        }

        return result;
    }
};