Problem Link: https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    
-----------------------------------------------------------------------------------------------------------------------------------  
    // Brute Force
    // Method 1
    // 1. For each buidling, find the maximum height of buidling on both side ie right side and left side.
    // 2. Each building can trap std::min(max_height_on_right, min) - height of that building
    // TC: O(N^2)
    // SC: O(1N)
    
-----------------------------------------------------------------------------------------------------------------------------------  
    // Method 2 Using extra space of two vector
    // The brute force method can be optimised if we can save the max height on left and right of each building in a vector.
    // TC: O(N)
    // SC: O(N+N)
    int trap(vector<int>& height) {
        int n = height.size();
        // base condition
        if (n == 0) { return 0; }
        
        std::vector<int> maxBuildingOnRight(n, 0);
        std::vector<int> maxBuildingOnLeft(n,0);
        
        // filing left 
        maxBuildingOnLeft[0] = height[0];
        for (int i = 1; i < n; ++i) {
            maxBuildingOnLeft[i] = std::max(height[i], maxBuildingOnLeft[i-1]);
        }
        
        
        
        // filling right
        maxBuildingOnRight[n-1] = height[n-1];
        for (int i = n-2; i >= 0; --i) {
            maxBuildingOnRight[i] = std::max(height[i], maxBuildingOnRight[i+1]);
        }
        
        
        int trappedWater = 0;
        for (int i = 0; i < n; ++i) {
            trappedWater += std::min(maxBuildingOnLeft[i], maxBuildingOnRight[i]) - height[i];
        }
        
        return trappedWater;
    }
    
-----------------------------------------------------------------------------------------------------------------------------------  
    // Method 3: The method 2 can be more optimised we don't need to store the right max building height.
    // It can be saved in a variable say maxHeightEncounteredInRight init to height[n-1] and whenver a higher value encountered while calculating the water trapped change it to new found value.
    // More Clear with code.
       int trap(vector<int>& height) {
        int n = height.size();
        // base condition
        if (n == 0) { return 0; }
        
        
        std::vector<int> maxBuildingOnLeft(n,0);
        
        // filing left 
        maxBuildingOnLeft[0] = height[0];
        for (int i = 1; i < n; ++i) {
            maxBuildingOnLeft[i] = std::max(height[i], maxBuildingOnLeft[i-1]);
        }
    
        int trappedWater = 0;
        int maxHeightEncounteredInRight = height[n-1];
        for (int i = n-1; i > 0; --i) {
            maxHeightEncounteredInRight = std::max(maxHeightEncounteredInRight, height[i]);
            trappedWater += std::min(maxBuildingOnLeft[i], maxHeightEncounteredInRight) - height[i];
        }
        
        return trappedWater;
    }
    
    
};
