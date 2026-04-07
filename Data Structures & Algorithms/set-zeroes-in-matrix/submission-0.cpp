class Solution {
public:
    vector<vector<int>> setZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int row[n] ={0};
        int col[m] = {0};

        for(int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(mat[i][j] == 0)
                {
                    row[i] = 1; 
                    col[j] = 1;
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j=0; j < m; j++)
            {
                if(row[i] == 1 || col[j] == 1)
                {
                    mat[i][j] = 0;
                }
            }
        }
        return mat;
    }
};
