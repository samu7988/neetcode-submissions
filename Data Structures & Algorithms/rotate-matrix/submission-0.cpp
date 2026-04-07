class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int row =  mat.size();
        int col = mat[0].size();
        int temp = 0;

        for(int i = 0 ; i < row; i++)       //transpose
        {
            for(int j = 0 ; j < col; j++)
            {
                if(i < j)
                {
                    temp      = mat[i][j];
                    mat[i][j] = mat[j][i];
                    mat[j][i] = temp;
                }
            }
        }
        //reverse

        for(int i = 0; i < row; i++)
        {
            // for(int j = 0; j < col/2; j++)
            // {
                // int temp                = mat[i][j];
                // mat[i][j]           = mat[i][col - 1 - j];
                // mat[i][col - 1 - j] = temp;
                reverse(mat[i].begin(), mat[i].end());
            // }
        }
    }
};
