class Solution {
public:
    int isSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, int row, int col) {
        // if out of bound and grid2{i,j} is water does not necessarily means that it cannot be sub-island
        if (i < 0 || i == row || j < 0 || j == col || grid2[i][j] == 0) return 1;
        // reached here that means grid2[i][j] == 1
        // marking visited grid2{i,j}
        grid2[i][j] = 0;
        int res = true; // making assumtion that both trees are same
        
        // going over all 4-directions
        res &=  isSubIsland(grid1, grid2, i+1, j, row, col);
        res &=  isSubIsland(grid1, grid2, i-1, j, row, col);
        res &=  isSubIsland(grid1, grid2, i, j+1, row, col);
        res &=  isSubIsland(grid1, grid2, i, j-1, row, col);
        return res & grid1[i][j];
    }
    
    
    
    // The intuition here: Think of grid as tress and we are comparing two trees.
    // Applying DFS on both grid together
    /*
        Time Complexity: O(m*n) m - row and n - col
        Space Compelxity: O(1)
    */
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        int row = grid1.size();
        int col = grid1[0].size();
        int subIslandsCount = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid2[i][j] == 1) /*if {i,j} is an island, apply dfs*/ {
                    if (isSubIsland(grid1, grid2, i, j, row, col))
                        ++subIslandsCount;
                    OR
                        subIslandsCount+=isSubIsland(grid1, grid2, i, j, row, col);
                }
            }
        }
        
        return subIslandsCount;
    }
};
