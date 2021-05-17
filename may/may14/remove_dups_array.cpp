https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    // TC: O(N)
    // SC: O(1)
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int i = 0;
        for(int j = 1; j < n; ++j) {
            if (nums[i] == nums[j]) {
                continue;
            }
            i++;
            nums[i] = nums[j];
        }
        return i+1;
    }
};
