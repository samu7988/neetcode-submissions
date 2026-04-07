class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>v;
        int left = 1;
        int right = 1;
        for(int i = 0 ; i < nums.size(); i++)
        {
            for(int j = i+1 ; j < nums.size(); j++)
            {
                right *= nums[j];
            }
            for(int j = i-1 ; j >= 0; j--)
            {
                left *= nums[j];
            }
            v.push_back(right * left);
            left = 1;
            right = 1;

        }
        return v;

    }
};
