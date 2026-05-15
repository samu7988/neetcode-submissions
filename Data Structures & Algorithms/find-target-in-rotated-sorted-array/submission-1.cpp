/*
At every step, ONE half is GUARANTEED to be sorted in a rotated array.

Step 1: Find which half is sorted (compare nums[low] and nums[mid])
Step 2: Check if target is within that SORTED half's range
        - If YES → search that half
        - If NO  → search the OTHER half (unsorted side)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low  = 0;                                                       // left pointer
        int high = nums.size() - 1;                                         // right pointer
        int mid  = 0;                                                        // middle index

        while (low <= high)
        {
            mid = (low + high) / 2;                                         // find mid

            if (nums[mid] == target)
                return mid;                                                  // target found → return index
            
            // ── Identify SORTED half — LEFT side is sorted ──
            if (nums[low] <= nums[mid])
            {
                // check if target lies WITHIN the sorted left part
                if (nums[low] <= target && target <= nums[mid])
                {
                    high = mid - 1;                                          // target is in left sorted half → go LEFT
                }
                else
                {
                    low = mid + 1;                                           // target not in left → search RIGHT (unsorted part)
                }
            }
            // ── RIGHT side is sorted ──
            else
            {
                // check if target lies WITHIN the sorted right part
                if (nums[mid] <= target && target <= nums[high])
                {
                    low = mid + 1;                                           // target is in right sorted half → go RIGHT
                }
                else
                {
                    high = mid - 1;                                          // target not in right → search LEFT (unsorted part)
                }
            }
        }
        return -1;                                                            // target not found
    }
};
