class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1;                                       // slowest possible speed (1 banana/hr)
        int high = *max_element(piles.begin(), piles.end()); // fastest ever needed (biggest pile)
        int result = high;                                  // best answer so far
        
        while (low <= high)
        {
            int k = (low + high) / 2;                      // try this speed
            
            // ── calculate hours needed at speed k ──
            long long hours = 0;
            for (int pile : piles) {
                hours += (pile + k - 1) / k;                // ceiling of pile/k
            }
            
            if (hours <= h)                                 // finished in time
            {
                result = k;                                 // save as best answer
                high = k - 1;                               // try SMALLER speed
            }
            else                                             // too slow
            {
                low = k + 1;                                // must try FASTER
            }
        }
        return result;
    }
};