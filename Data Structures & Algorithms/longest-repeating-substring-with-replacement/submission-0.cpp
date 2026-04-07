class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0};      // frequency of each char in window
        int maxFreq = 0;         // highest frequency char in window
        int left = 0;            // left pointer
        int result = 0;          // best answer

        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;                      // expand window
            maxFreq = max(maxFreq, freq[s[right] - 'A']); // update max freq

            // window size - maxFreq = characters we need to replace
            int windowSize = right - left + 1;
            if (windowSize - maxFreq > k) {
                freq[s[left] - 'A']--;   // shrink window from left
                left++;
            }

            result = max(result, right - left + 1);
        }

        return result;
    }
};