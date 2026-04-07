class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int mid = 0;

        while(low <= high)         
        {
            mid = (low + high)/2;                        //find mid 

            if(nums[mid] == target)
            {
                return mid;
            }
            if(nums[low] <= nums[mid])                  //Identify sorted area -> left 
            {
                if(nums[low] <= target && target <= nums[mid])    //if target is in between sorted part 
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;                               // do not forget to check unsorted area as well 
                }
            }
            else                                                     //Identify sorted area -> right
            {
                if(nums[mid] <= target && target <= nums[high])      //check if target is lying there 
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
