// Problem Link : https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/
//
class Solution {
public:
    
    *********************************************************
    // Method 0: Sort the vector and return (n - k) index data 
    // TC: O(NlogN)
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        // add check if k > n in interview or ask constraint from interviewer
        std::sort(nums.begin(), nums.end());
        return nums[n - k];
        
    }
    **********************************************************
    
    // Method 1: Can be solved using Balanced BST ie. RBT or AVL etc as well.
    // Insert each value from nums
    // Height of Balanced BST can be worst as log2n only
    // Finding kth largest will be O(height(->logN) + k)
    // SC: O(N)
    
    
    *********************************************************
    // Helper for Method 2
    void maxHeapify(std::vector<int> &nums, int i, int n) {
        int j = 0;
        while (2*i <= n) {
            j = 2*i;
            if (j < n && nums[j-1] < nums[j])
                ++j;
            if (nums[i-1] < nums[j-1])
                std::swap(nums[i-1], nums[j-1]);
            else
                break;
            i = j;
        }
    }
    
    
    // Helper for Method 2
    // TC: O(N)
    void maxHeap(std::vector<int> &nums, int n) {
        for (int i = n/2; i > 0; --i) {
            maxHeapify(nums, i, n);
        }
    }
    
    

    // Method 2: Using max Heap
    // Algo:
    // 1. Create max heap of nums - O(N)
    // 2. Remove the first k-1 element from root and heapify it - O(KlogN)
    // 3. Return the root element - O(1)
    // TC: O(N + klogN)
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        // step 1
        maxHeap(nums, n);
        
        // step 2
        while (k > 1) {
            std::swap(nums[0], nums[n-1]);
            --n;
            maxHeapify(nums, 1, n);  1 -> index to call heapify upon
            --k;
        }
        
        // step 3
        return nums[0];
    }
    **********************************************************
    
    // Helper for Method 3
    void minHeapify(std::vector<int>  &nums, int i, int k) {
        int j = 0;
        while (2*i <= k) {
            j = 2*i;
            if (j < k && nums[j-1] > nums[j])
                ++j;
            if (nums[i-1] > nums[j-1])
                std::swap(nums[i-1], nums[j-1]);
            else
                break;
            i = j;
        }
    }
    
    
    // Helper for Method 3
    void minHeap(std::vector<int> &nums, int n, int k) {
        for (int i = k/2; i > 0; --i) {
            minHeapify(nums, i, k);
        }
    }
    
    // Method 3: Using Min Heap
    // Algo:
    // 1. Create a min heap of size k from nums(first k elements) - O(k) -> The idea here is we want to get the kth largest and min is of that size
    // 2. For rest of (n-k) element if root(heap) < nums[k, k+1....n--1] that means it is going to be part of the heap may not be the answer but should be part of heap because the lesser value could not be the answer ever. 
    // TC for step -> O(((n-k)logk) -> (n-k) elements & logk heapify time
    // 3. First Dry run on few examples. After step 1 and step2 the root will have the kth largest element
    int findKthLargest(std::vector<int> &nums, int k) {
        int n = nums.size();
        // step 1
        minHeap(nums, n, k);
        
        // step 2
        for (int i = k; i < n; ++i) {
            if (nums[0] < nums[i]) { // root is less than nums[i]
                nums[0] = nums[i]; // insert in heap
                minHeapify(nums, 1, k); // correcting heap property
            }
        }
       
        // step 3
        return nums[0];
    }
};

// In C++ priority queue stl can be used to implement min and max heap -> https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/

