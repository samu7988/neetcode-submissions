class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int sum = 0;
        reverse(digits.begin(), digits.end());

        for(int i = 0 ; i < digits.size(); i++)
        {
            sum = digits[i] + carry;
            digits[i] = (sum%10);
            carry = sum/10;
        }

        if(carry == 1)
        {
            digits.push_back(carry);
        }
        reverse(digits.begin(),digits.end());
        return digits;
        
    }
};