class Solution:
    def rotate(self, mat: list[list[int]]) -> None:
        row = len(mat)                                    # int row = mat.size()
        col = len(mat[0])                                 # int col = mat[0].size()
        
        # ── Transpose: swap mat[i][j] with mat[j][i] ──
        for i in range(row):                              # for(int i = 0; i < row; i++)
            for j in range(col):                          # for(int j = 0; j < col; j++)
                if i < j:                                  # only upper triangle
                    mat[i][j], mat[j][i] = mat[j][i], mat[i][j]   # ✅ Pythonic swap
        
        # ── Reverse each row ──
        for i in range(row):
            mat[i].reverse()                              # reverse in place