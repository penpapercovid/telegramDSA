class Solution {
public:
    void dfs(vector<vector<int>>& image, int x, int y, int oldColor, int newColor) {
        // {x,y} is oldColor, fill it up with new color and apply dfs.
        if (image[x][y] == oldColor) {
            image[x][y] = newColor;
            // right dir
            if (y+1 < image[0].size())
                dfs(image, x, y+1, oldColor, newColor);
            // left dir
            if (y >= 1)
                dfs(image, x, y-1, oldColor, newColor);
            // upward dir
            if (x >= 1)
                dfs(image, x-1, y, oldColor, newColor);
            // downward dir
            if (x+1 < image.size())
                dfs(image, x+1, y, oldColor, newColor);    
        }
    }
    // Applying dfs on {sr,sc} and start filling the image pixel's 
    // TC: O(N) where N is number of elements in image
    // SC: O(N) size of call stack when calling dfs function
    /*
        Runtime: 4 ms, faster than 98.59% of C++ online submissions for Flood Fill.
        Memory Usage: 14 MB, less than 55.22% of C++ online submissions for Flood Fill.
    */
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        int row = image.size();
        int col = image[0].size();
        // oldColor is same as newColor, no flood fill will occur.
        if (oldColor != newColor) 
            dfs(image, sr, sc, oldColor, newColor);      
        
        return image;
    }
};
