class Solution {
public:
    int hammingWeight(uint32_t n) {
        bool bit = 0;
        int cnt = 0;
        for (int i = 0 ; i < 32; i++)
        {
            bit = n & (1 << i);
            if(bit == 1)
            {
                cnt++;
            }
        }
        return cnt;
    }
};
