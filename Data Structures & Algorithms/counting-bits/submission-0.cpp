class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>v;
        int num = 0;
        int cnt = 0;
        for(int i = 0 ; i <= n; i++)
        {
            num = i;
            
            while(num)
            {
                num = num & (num -1);
                cnt++;
            }
            v.push_back(cnt);
            cnt = 0;
        }
        return v;
    }
};
