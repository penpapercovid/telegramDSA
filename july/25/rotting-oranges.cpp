class Solution {
private:
    enum CELLTYPE {
        EMPTY=0,
        FRESH,
        ROTTEN
    };
    
    
public:
    // Using BFS
    // Time Complexity: O(m*n)
    // Space Complexity: O(m*n)
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        // Applying BFS
        std::queue<std::pair<int/*x-coordinate*/, int/*y-coordinate*/>> q;
        // Getting all the co-ordinates of rotten tomatoes
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == ROTTEN) q.push({i, j});
            }
        }
        
        /// at this point it is quaranteed that q will contain all the coordinates of rotten tomatoes, so while dequeing we can in all direction for fresh tomatoes and rot them.
        
        int timeElapsed = 0;
        while (!q.empty()) {
            int size = q.size();
            // processing level by level just like we do level order traversal for a tree. Even in most of the matrix questions it is better to think them as a tree.
            bool canRot = false; // this will maintain if we rot atleast one orange then only timeElapsed should increase.
            while (size) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                // right-dir
                if (y+1 < col && grid[x][y+1] != EMPTY && grid[x][y+1] == FRESH) {
                    canRot = true;
                    q.push({x,y+1});
                    grid[x][y+1] = ROTTEN;
                }
                // left-dir
                if (y-1 >= 0 && grid[x][y-1] != EMPTY && grid[x][y-1] == FRESH) {
                    canRot = true;
                    q.push({x,y-1});
                    grid[x][y-1] = ROTTEN;
                }
                // upward-dir
                if (x-1 >= 0 && grid[x-1][y] != EMPTY && grid[x-1][y] == FRESH) {
                    canRot = true;
                    q.push({x-1,y});
                    grid[x-1][y] = ROTTEN;
                }
                // downward-dir
                if (x+1 < row && grid[x+1][y] != EMPTY && grid[x+1][y] == FRESH) {
                    canRot = true;
                    q.push({x+1,y});
                    grid[x+1][y] = ROTTEN;
                }               
                --size;
             }
             if (!canRot) break; /*
                                        [
                                           1, 0, 2
                                           1, 1, 0
                                           1, 0, 2
                                        ]
                                        In this case if we do not have canRot varialbe we will get timeElapsed as 2 which is incorrect, oranges cannot be rotten as rotted are within empty cells
                                    */
            ++timeElapsed;
        }
            
        // need to check if all oranges are rotted or not
        /*
            [
                2, 0, 1(can't be rotten)
                1, 1, 0
                2, 0, 1(can't be rotten)
            ]
        */
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == FRESH) {
                    timeElapsed = -1;
                    break;
                }
            }
        }
        
        
        return timeElapsed;
    }
};
