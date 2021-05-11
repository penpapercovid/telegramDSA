// Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array/description/
// 
// Source: Theory from Gayle Lakhmann 
// This is a classic binary search problem with a slight twist in standard BS where we can compare target with mid and figure out whether target is on left or right. But here the array is roated

// Consider examples {10,15,20,0,5} and {50, 5, 20, 30, 40}
// Both arrays have mid point of 20, but 5 appears on the left side of the one and right side of the other. So, comparing target with mid value is insufficient.
//
// However, if we look closer with specs on we can see that atleast one side of the array must be sorted normally (in incr. order). We can use that information van look at normally ordered half and determine whether to look right ot left side.
//
// For ex1. target = 5 and we can see that in example1 the left side is normally ordered because start(10) < mid(20). And since 5 is not between we must search the right half.
// For ex2. target = 5 and we can see that in example2 the right side is normally ordered because mid(20) < start(50). We need to check between if target falls between mid(20) and end(40) which it doesn;t so we will check on left side of the array.
//
//
//-----------------------------------------------------------------------------
// Handling Dups:
// ex {2,2,2,2,3,4,2}
// search 3
// We need to search the both halves in this case 
//-----------------------------------------------------------------------------
//
// --------------------------------------------------------------------------------
// Observations + Algorithm:
// 1. Atleast one half of the array must be ordered normall in increasing order. Find it.
// 2. If target fits in search space of normally ordered half. Search it
// 3. Else search other half.
// 4. If Dups are present and check if one half is same ie a[start]==a[mid] or a[end] == a[mid] search the other half if they are different. If not, check both sides of the halves.
// 5. Else return -1.
// --------------------------------------------------------------------------------

// TC: O(logN) if all elements are unique. otherwise O(N)
// SC: O(1) not considering functional stack created during recursion
class Solution {
public:
    int search(const std::vector<int> &nums, int start, int end, int target) {
        // Base Condition
        if (start > end) {
            return -1;
        }

        int mid = (start + end)/2;
        // if mid element is the target itself.
        if (nums[mid] == target) {
            return mid;
        }
        
        
        // Either the left or right half must be normally ordered. Find out which half is normally ordered.
        // Use that half to find which side to search.

        // left is normally ordered
        if (nums[mid] > nums[start]) {
            if (target >= nums[start] && target < nums[mid]) {
                return search(nums, start, mid-1, target); // search left as target is in between and half is normally ordered
            } else {
                return search(nums, mid+1, end, target); // search right
            }
        } else if (nums[start] > nums[mid]) { // right is normally ordered
            if (target > nums[mid] && target <= nums[end]) {
                return search(nums, mid+1, end, target);// search right as target is in between and half is normally ordered.
            } else {
                return search(nums, start, mid-1, target); // search left
           }
        } else if (nums[start] == nums[mid]) { // handles dups 
            if (nums[end] != nums[mid]) { // right half is different, search the target
                return search(nums, mid+1, end, target); // search left
            } else {
                // search the both halves
                int idx = search(nums, start, mid-1, target); // search left
                // search will return -1 in case couldn't find target.
                if (idx == -1) search(nums, mid+1, end, target); // search right
                else return idx;
            }
        }
        // reached here -> no element present with target value.
        return -1;
    }

    int search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size() - 1, target);
    }

};

