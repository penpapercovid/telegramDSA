class Solution {
public:
    bool isMoveSafe(vector<vector<int>>& image, int sr, int sc, int currentColor) {
        int row = image.size();
        int col = image[0].size();
        return sr >= 0 && sr < row && sc >= 0 && sc < col && (image[sr][sc] == currentColor);
    }
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int currentColor, int newColor) {
        if (isMoveSafe(image, sr, sc, currentColor) && currentColor != newColor)  {
            image[sr][sc] = newColor;
            // move in +x-direction
            dfs(image, sr+1, sc, currentColor, newColor);
            // move in -x-direction
            dfs(image, sr-1, sc, currentColor, newColor);
            // move in +y-direction
            dfs(image, sr, sc+1, currentColor, newColor);
            // move in -y-direction
            dfs(image, sr, sc-1, currentColor, newColor);
        }
    }
    // Time Compelxity: O(N), where N us number of pixels
    // Space Compelxity: O(N)
    
    /*
        Runtime: 8 ms, Memory Usage: 14 MB
    */
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int currentColor = image[sr][sc];       
        dfs(image, sr, sc, currentColor, newColor);
        return image;           
    }
};
