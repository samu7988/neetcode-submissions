class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int xor1 = 0;

        for(int i = 0 ; i < nums.size(); i++)
        {
            xor1 ^= nums[i];
        }
        for(int i = 0; i < (nums.size()+1); i++)
        {
            xor1 ^= i;
        }
        return xor1;
    }
};
