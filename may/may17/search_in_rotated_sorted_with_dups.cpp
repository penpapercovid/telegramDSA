Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution {
public:
    /*
    Time complexity : O(N) worst case, O(logN) best case, where N is the length of the input array.

    Worst case: This happens when all the elements are the same and we search for some different element. At each step, we will only be able to reduce the search space by 1 since arr[mid] equals arr[start] and it's not possible to decide the relative position of target from arr[mid]. Example: [1, 1, 1, 1, 1, 1, 1], target = 2.

    Best case: This happens when all the elements are distinct. At each step, we will be able to divide our search space into half just like a normal binary search.

    This also answers the following follow-up question:

    Would this (having duplicate elements) affect the run-time complexity? How and why?
    As we can see, by having duplicate elements in the array, we often miss the opportunity to apply binary search in certain search spaces. Hence, we get O(N) worst case (with duplicates) vs O(logN) best case complexity (without duplicates).

    Space complexity : O(1).
    */
    
    // Solution lies in the fact even though the array is rotated but still one of the two halves ie left and right will be sorted.
    bool search(vector<int> &nums, int left, int right, int target) {
        if (left > right) return false;
        int mid = left + (right-left)/2;
        if (nums[mid] == target) return true;   
        
        // Check if left is normally ordered
        if (nums[left] < nums[mid]) {
            if (target >= nums[left] && target < nums[mid]) {
                return search(nums, left, mid-1, target);// search left
            } else {
                return search(nums, mid+1, right, target); // search right
            }
        } else if (nums[left] > nums[mid])  { // => right is normally ordered
            if (target > nums[mid] && target <= nums[right]) {
                return search(nums, mid+1, right, target); // search right
            } else {
                return search(nums, left, mid-1, target); // search left
            }
        
        } else { // a[left] == a[mid] dups are there between left and mid index
            // check on right side if there are different elements present
            if (nums[mid] != nums[right]) {
                return search(nums, mid+1, right, target); // search right
            } else {
                // need to search both sides
                bool res = search(nums, mid+1, right, target); // search left
                if (res) {
                    return res; // found on right side
                } else {
                    return search(nums, left, mid-1, target); // search left
                }
            }
        }
        
        return false;
    }
        
    
    
    bool search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size()-1, target);
    }
};


