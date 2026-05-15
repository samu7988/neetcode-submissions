class Solution {
public:
    int reverse(int x) {
        int reversed = 0;                                                          // stores reversed number
        
        while (x != 0) {
            int digit = x % 10;                                                    // extract last digit of x
            x /= 10;                                                                // remove last digit from x
            
            // ── check positive overflow BEFORE doing reversed * 10 + digit ──
            // INT_MAX = 2147483647 → INT_MAX/10 = 214748364, last digit = 7
            if (reversed > INT_MAX / 10 ||                                         // already too big to multiply by 10
               (reversed == INT_MAX / 10 && digit > 7))                            // exact boundary, but digit pushes it over
                return 0;                                                           // overflow → return 0
            
            // ── check negative overflow BEFORE doing reversed * 10 + digit ──
            // INT_MIN = -2147483648 → INT_MIN/10 = -214748364, last digit = -8
            if (reversed < INT_MIN / 10 ||                                         // already too negative
               (reversed == INT_MIN / 10 && digit < -8))                           // exact boundary, but digit pushes it under
                return 0;                                                           // underflow → return 0
            
            reversed = reversed * 10 + digit;                                      // shift reversed left, append new digit
        }
        
        return reversed;                                                            // return final reversed number
    }
};