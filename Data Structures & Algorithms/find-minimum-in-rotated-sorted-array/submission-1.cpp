// identify the sorted area first if(nums[low] <= nums[mid])
// after identifying try to look for min  in sorted area by considering one of the as min_a 


class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = INT_MAX;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[low] <= nums[mid])     // ── LEFT half is sorted ──
        {
            ans = min(nums[low], ans);  // smallest in left sorted = nums[low]
            low = mid + 1;              // search RIGHT (rotation might be there)
        }
        else                             // ── RIGHT half is sorted ──
        {
            ans = min(nums[mid], ans);  // smallest in right sorted = nums[mid]
            high = mid - 1;             // search LEFT (rotation might be there)
        }
    }
    return ans;
}
};
