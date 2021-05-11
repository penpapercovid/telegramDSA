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
        if (n < 3) { // not enough number to find triplets
            return {};
        }

        // sorting the vector - O(NlogN)
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n-2; ++i) {

        }
    }
};
