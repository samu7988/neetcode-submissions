class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        
        int m = mat.size();
        int n = mat[0].size();

        int row = 0;
        int col = 0;
        int mid = 0;
        int low = 0;
        int high = (m*n) - 1;

        while(low <= high)
        {
            mid = (low + high)/2;

            row = mid / n;
            col = mid % n;

            if(mat[row][col] == target)
            {
                return true;
            }
            else if (mat[row][col] < target)
            {
                low = mid + 1;
            }
            else if (mat[row][col] > target)
            {
                high = mid - 1;
            }
        }
        return false;
    }
};
