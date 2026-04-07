class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
         int j = s.size()-1;
         while(i <= j)
         {
            if(s[i] == ' ' || isalnum(s[i]) == 0)
            {
                i++;
            }
            else if(s[j] == ' ' || isalnum(s[j]) == 0)
            {
                j--;
            }
            else if(tolower(s[i]) == tolower(s[j]))
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
         }
         return true;
    }
};
