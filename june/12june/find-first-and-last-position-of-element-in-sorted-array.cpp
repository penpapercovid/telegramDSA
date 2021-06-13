Problem Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:

    // search first index
    int search(const vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        int potentialIndx = -1;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (nums[mid] == target) {
                potentialIndx = mid;
                if (mid > 0 && nums[mid] != nums[mid-1]) {
                    return mid;
                }
                else {
                    high = mid-1;
                }
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return potentialIndx;
    }
    // search last index
    int search(const vector<int>& nums, int startIndx, int target) {
        int n = nums.size();
        int low = startIndx, high = n-1;
        int potentialIndx = -1;
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (nums[mid] == target) {
                potentialIndx = mid;
                if (mid+1 < n && nums[mid] != nums[mid+1]) {
                    return mid;
                } else {
                    low = mid+1;
                }
            } else if (nums[mid] > target) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return potentialIndx;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        std::vector<int> result(2, -1);
        int n = nums.size();
        if (n == 0) return result;

        result[0] = search(nums, target); // find first index of the target in the nums vector

        if (result[0] == -1) {// => target is not present.
            return result;
        }

        // search the target after result[1] index.
        result[1] = search(nums, result[0] + 1, target);

        if (result[1] == -1) {// // if no second item is present.
            result[1] = result[0];
        }
        return result;
    }
};





--------------------------------------------------------OLD SOLUTION--------------------------------------------------------------------------------------------------------------------------------------

class Solution {
public:
    int searchForFirstIndex(vector<int>& nums, int start, int end, int target) {
        if (start > end) {
            return -1;
        }
        
        while (start <= end) {
            int mid = start + (end-start)/2;
            if (nums[mid] == target) {
                if (mid > start && nums[mid-1] != target) {
                    return mid;
                } else if (start == end){
                    return mid;
                } else {
                    end = mid;
                }
            } else if (nums[mid] > target) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return -1;
    }
    
    int searchForSecondIndex(vector<int>& nums, int start, int end, int target) {
        if (start > end) {
            return -1;
        }
        
        while (start <= end) {
            int mid = start + (end-start)/2;
            if (nums[mid] == target) {
                if (mid < end && nums[mid+1] != target) {
                    return mid;
                } else if (start == end){
                    return mid;
                } else {
                    start = mid+1;
                }
            } else if (nums[mid] > target) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return -1;
    }
    // TC - O(logn)
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0 || nums[size-1] < target || nums[0] > target) {
            return {-1, -1};
        }  
        std::vector<int> res;
        int firstIndex = searchForFirstIndex(nums, 0, size-1, target);
        int secondIndex = searchForSecondIndex(nums, firstIndex+1, size-1, target);
        std::cout << "firstIndex:" << firstIndex <<  "secondIndex:" << secondIndex << std::endl;
        secondIndex = (secondIndex == -1) ? firstIndex : secondIndex;
        return {firstIndex, secondIndex};
    }
};
