Problem Link: https://leetcode.com/problems/3sum/

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.


Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []


class Solution {
public:
    // Method 1: Using Brute Force
    // Using three loops
    // O(N^3)
    //

    // Method 2: Sorting the vector
    // TC: O(NlogN(sorting) + N^2)
    // SC: O(1)
    //
    -----------------------------------------------------------------------------------------------
    Observation: we need to find unique pair such that a + b + c = k where k = 0
        3Sum problem is extension of 2Sum problem(a + b = k) if we fix one variable say c then it is 2Sum 
    problem where we need to find a + b = k where k = -c. 
    ----------------------------------------------------------------------------------------------
    
    vector<vector<int>> threeSum(vector<int>& nums) {
         int n = nums.size();
        if (n < 3) {
            return {};
        }
        
        // result to return
        std::vector<std::vector<int>> res;
        
        // sorting takes O(nlogn)
        std::sort(nums.begin(), nums.end());
        
        // TC: O(n^2)
        for (int i = 0; i < n - 2; ++i) {
            int j = i+1; // next to i
            int k = n-1; // last index
            int c = -nums[i]; // can be thought of k in Two Sum Problem
            
            // fixedTarget cannot be less than zero
            // Optimisation
            // If nums[i] > 0 => fixedTarget is < 0 that means there is no number negative in later indices as well
            // , adding positive will never result to zero.
            if (c < 0) {
                break;
            }
            
            while (j < k) {
                int sum = nums[j] /*a*/ + nums[k]/*b*/; // exact two problem a + b = c where c = k and k = -nums[i]
                if (sum == c) {
                    // pushing tupletupletuple found in res 
                    std::vector<int> tuple(3, 0);
                    tuple[0] = nums[i];
                    tuple[1] = nums[j];
                    tuple[2] = nums[k];
                    res.push_back(tuple);
                    
                    // handling repeation for value at nums[j]
                    // excluding the repeated value
                    while (j < k && tuple[1] == nums[j]) ++j;

                    // handling repeation for value at nums[k]
                    // excluding the repeated value
                    while (k > j && tuple[2] == nums[k]) --k;
                } else if (sum > c) {
                    --k;
                } else {
                    ++j;
                }
           }
  
            // handling repeation for value at nums[i]
            // excluding the repeated value
            
            while (i < n-1 && nums[i] == nums[i+1]) ++i;
        }
        
        return res;
    }
};
