Problem Link: https://leetcode.com/problems/sort-colors/
class Solution {
public:
    /*Sorting the vector is not allowed*/
    
------------------------------------------------------------------------
    // Method  1: Two Traversal 
    /*  1. Count the frequency of each character.
        2. Put it back in original vector
    */
    // TC: O(N+N)
------------------------------------------------------------------------
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> count(3, 0);
        
        for (auto const i: nums) {
            switch(i) {
                case 0: ++count[0];
                    break;
                case 1: ++count[1];
                    break;
                case 2: ++count[2];
                    break;
            }
        }
        
        int j = 0;
        for (int i = 0 ; i < 3; ++i) {
            while (count[i]) {
                nums[j++] = i;
                --count[i];
            }
        }
    }
    
    
------------------------------------------------------------------------
    // Method 2: This problem is also known as Dutch Flag Problem
    // Only one traversal
    // TC: O(N)
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0, k = n-1;
        while (j <= k) {
            switch(nums[j]) {
                case 0:
                        std::swap(nums[i++], nums[j++]);
                        break;
                case 1:
                        j++;
                        break;
                case 2:
                        std::swap(nums[j], nums[k])
                            
                        break;
            }
        }
    }
    
};
