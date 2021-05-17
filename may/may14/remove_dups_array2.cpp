Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/


class Solution {
public:
  /*
    Brute Force:
    1. Using Two loops.
    2. Calculate the frequency of each item if > 2 then remove it from the array.
    3. keep doing the same for all item in the array.
    4. return the length of the array.
    TC: O(N^2)
  */


    // Method 1: Using Two Pointers
    // TC: O(N)
    // SC: O(1)
-----------------------------------------------------------------------------
METHOD 1
    int removeDuplicates(vector<int>& nums) {
        int i = 1;
        int count = 1; // to maintain the frequency of each character. all items must have atleast 1 frequency that is by default.
        int n = nums.size();
        for (int j = 1; j < n; ++j) {
            if (nums[j] == nums[j-1]) ++count; // same item encountered
            else count = 1; // new item so count is 1
            if (count <= 2)
                nums[i++] = nums[j];
        }
        return i;
    }
    
-----------------------------------------------------------------------------
METHOD 2
    // solution from discussion section. Very Optimised also can be generalized for k
    int removeDuplicates(vector<int> &nums) {
        int i = 0;
        for(int n : nums) {// for every number in nums
            if (i < 2 || n > nums[i-2])
                nums[i++] = n;
        }
        return i;
    }
-----------------------------------------------------------------------------
    // Above Solution can be generalized for most k items
    int removeDuplicates(vector<int> &nums, int k) { // here in above example k = 2
        int i = 0;
        for(int n : nums) {// for every number in nums
            if (i < k || n > nums[i-k])
                nums[i++] = n;
        }
        return i;
    }
    int removeDuplicates(vector<int> &nums) {
        return removeDuplicates(nums, 2);
    }

};
