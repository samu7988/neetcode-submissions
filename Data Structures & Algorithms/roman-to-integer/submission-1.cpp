class Solution {
public:
    int romanToInt(string s) {
        map<char,int>mp;

        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int val = 0;

        for(int i = 0 ; i < s.size();)
        {   
            char a = s[i];
            if(a == 'I')
            {
                char b = s[i+1];
                if( b == 'X' || b == 'V'){
                    val += mp[b] - mp[a];
                    i += 2;
                }
                else{
                    val += mp[a];
                    i += 1;
                }
            }
            else if(a == 'X')
            {
                char b = s[i+1];
                if( b == 'L' || b == 'C'){
                    val += mp[b] - mp[a];
                    i += 2;
                }
                else{
                    val += mp[a];
                    i += 1;
                }
            }
            else if(a == 'C')
            {
                char b = s[i+1];
                if( b == 'D' || b == 'M'){
                    val += mp[b] - mp[a];
                    i += 2;
                }
                else{
                    val += mp[a];
                    i += 1;
                }
            }
            else{
                val += mp[a];
                 i+= 1;
            }
        }


        return val;



    }
};