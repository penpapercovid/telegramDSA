class Solution {
public:
    // Applying DFS - This is a standard DFS problem
    // Algorithm: 
    /*
     1. Iterative over the matrix, when item is 1(Land) apply dfs on that index.
     2. Count the number of 1 reachable from that index, total will be the area of that island.
     3. Return the maximum area found else return 0(no island present in grid)
    */
    bool isMoveSafe(vector<vector<int>>& grid, int i, int j) {
       int row = grid.size();
       int col = grid[0].size(); 
       return i >= 0 && i < row && j >= 0 && j < col && grid[i][j] == 1;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int &currArea) {
        if (isMoveSafe(grid, i, j)) {
            grid[i][j] = 0; // marking visited
            ++currArea; // increasing area by 1
            // move in +x-direction
            dfs(grid, i+1, j, currArea);
            // move in -x-direction
            dfs(grid, i-1, j, currArea);
            // move in +y-direction
            dfs(grid, i, j+1, currArea);
            // move in -y-direction
            dfs(grid, i, j-1, currArea);
        }
    }
    
    /*
        Recursive Solution
        Time Compexity: O(n*m) where n is number of row and m is number of column
        Space Complexity: O(1), ignoring functional stack created due to recursion
        Runtime: 12ms and Space: 23.3 MB
    */
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        /*
            if (row == 0) return 0; // this condition can be ignored as per constraint
        */
        int col = grid[0].size(); 
        int maxArea = 0;
        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1) {
                    int currArea = 0;
                    dfs(grid, i, j, currArea);
                    maxArea = std::max(maxArea, currArea);
                }
                    
            }
        }
        
        return maxArea;
    }
};

Can be solved using iterative approach as well by using a stack
