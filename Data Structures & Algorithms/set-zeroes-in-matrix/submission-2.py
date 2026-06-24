class Solution:
    def setZeroes(self, mat: list[list[int]]) -> None:
        n = len(mat)                                      # int n = mat.size()
        m = len(mat[0])                                   # int m = mat[0].size()
        
        row = [0] * n                                     # int row[n] = {0}
        col = [0] * m                                     # int col[m] = {0}
        
        # ── First pass: mark rows and cols that contain a 0 ──
        for i in range(n):                                # for(int i = 0; i < n; i++)
            for j in range(m):                            # for(int j = 0; j < m; j++)
                if mat[i][j] == 0:
                    row[i] = 1
                    col[j] = 1
        
        # ── Second pass: set zeros based on marks ──
        for i in range(n):
            for j in range(m):
                if row[i] == 1 or col[j] == 1:
                    mat[i][j] = 0