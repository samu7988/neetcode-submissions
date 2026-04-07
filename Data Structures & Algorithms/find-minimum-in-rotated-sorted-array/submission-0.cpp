// identify the sorted area first if(nums[low] <= nums[mid])
// after identifying try to look for min  in sorted area by considering one of the as min_a 


class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = INT_MAX;

        while(low <= high)
        {
            int mid = (low + high)/2;

            if(nums[low] <= nums[mid])
            {
                ans = min(nums[low], ans);
                low = mid + 1;
            }
            else
            {
                ans = min(nums[mid], ans);
                high = mid - 1;
            }
        }
        return ans;
    }
};
