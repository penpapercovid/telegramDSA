class Solution {
public:
    // Brute Force: Will Result in TLE
    // Rotate the k unit 1 by 1
    // Time Complexity: O(nk)
    // void rotate(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     k = k % n; // reducing the unnecessary rotation in some cases like k = 14 n = 7 no rotation required or n = 7 k = 8 only one rotation is required
    //     while (k) {
    //         int last = nums[n-1];
    //         for (int i = n-2; i >= 0; --i) {
    //             nums[i+1] = nums[i];
    //         }
    //         nums[0] = last;
    //         --k;
    //     }
    // }
    
    // Method 1: Using extra space
    // Time Compelxity: O(n)
    // Space Complexity: O(n)
    /*
    Runtime: 28 ms, faster than 70.48% of C++ online submissions for Rotate Array.
    Memory Usage: 25.7 MB, less than 16.03% of C++ online submissions for Rotate Array.
    */
    // void rotate(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     k = k % n; // reducing the unnecessary rotation in some cases like k = 14 n = 7 no rotation required or n = 7 k = 8 only one rotation is required
    //     std::vector<int> answer(nums.size(), 0);
    //     // copy item from to n-k to n
    //     int j = 0;
    //     for (int i = n-k; i < n; ++i) 
    //         answer[j++] = nums[i];
    //     // copy item from 0 to n-k
    //     for (int i = 0; i < n-k; ++i)
    //         answer[j++] = nums[i];
    //     // copying back all n items
    //     for (int i = 0; i < n; ++i) 
    //         nums[i] = answer[i];
    // }
    
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) 
            std::swap(nums[start++], nums[end--]);        
    }
    
    // Method 3: Using reverse concept
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    /*
        Runtime: 28 ms, faster than 70.48% of C++ online submissions for Rotate Array.
        Memory Usage: 25 MB, less than 71.03% of C++ online submissions for Rotate Array.
    */
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums, 0, n-1);// reverse all n items
        reverse(nums, 0, k-1); // reverse first k
        reverse(nums, k, n-1); // reverse n-k
    }
};
