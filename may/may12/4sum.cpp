Problem Link: https://leetcode.com/problems/4sum/

class Solution {
public:
    // Brute Force using four pointers
    // TC: O(N^4)
    // Think about space
    /*
        for (i:0 to < n-3)
            for (j:i+1 to < n-2)
                for (k:j+1 to < n-1)
                    for (l:k+1 to < n)
                        if (nums[i] + nums[j] + nums[k] + nums[l]) == k
                            set.insert({nums[i], nums[j], nums[k], nums[l]});
    
    */
    
    // Optimised Method
    // TC: O(N^3)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // base condition
        int n = nums.size();
        // nothing to work, no such tuple present
        if (n < 4) {
            return {};
        }
        
        // Extension of three Sum Problem wehere a + b + c = k 
        // 4Sum - a + b + c = -(k + d), d is fixed or say of the value is fixed
        
        // sorting takes O(nlogn)
        std::sort(nums.begin(), nums.end());
        
        // result to return
        std::vector<std::vector<int>> res;
        
        for (int i = 0; i < n-3; ++i) {
            int newTarget = (target - nums[i]); // (k - d)
            // now problem reduced to 3Sum
            // a + b + c = newTarget
            for (int j = i+1; j < n-2; ++j) {
                int newTarget2 = (newTarget - nums[j]);
                // now problem reduced to 2 Sum
                // a + b = newTarget2
                int l = nums.size() - 1;
                int k = j + 1;
                while (k < l) {
                    int sum = nums[k] + nums[l];
                    if (sum == newTarget2) {
                        std::vector<int> tuple(4, 0);
                        tuple[0] = nums[i];
                        tuple[1] = nums[j];
                        tuple[2] = nums[k];
                        tuple[3] = nums[l];
                        res.push_back(tuple);
                        
                        // handling repetition for data at index k 
                        while (k < l && tuple[2] == nums[k]) ++k;
                        // handling rep' for data at index l
                        while (k < l && tuple[3] == nums[l]) --l;
                        
                    } else if (sum > newTarget2) {
                        --l;
                    } else {
                        ++k;
                    }
                }
                // handling rep' for data at index j
                -----------------------------------------------
                    IMPORTANT, CAN CAUSE RUNTIME ERROR 
                    eg [0,0,0,0], target = 0
                while (j < n-2 && nums[j] == nums[j+1]) ++j;
                --------------------------------------------------
            }
            // handling rep' for data at index i
            ------------------------------------------------
                    IMPORTANT, CAN CAUSE RUNTIME ERROR 
                    eg [0,0,0,0], target = 0
            while (i < n - 1 && nums[i] == nums[i+1]) ++i;
            -------------------------------------------------
        }
        return res;
    }
};
