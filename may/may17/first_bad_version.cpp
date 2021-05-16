Problem Link: https://leetcode.com/problems/first-bad-version/submissions/


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    // Algorithm: Need to minimise the call to isBadVersion. so, cannot go with linear approach. 
    // need to do a binary search on it.
    // The idea here is simple if mid is not bad version then it will be lie on right side of mid
    // and if mid is the bad version then either it could be the first bad version or the first bad version lies on
    // left side of the mid. Keep comparing it with the already old version with the new mid.
    
    // TC: O(logn). The search space is halved each time, so the time complexity is O(logn)
    // SC: O(1)
    int firstBadVersion(int n) {
        int firstBadVer = n;
        
        int start = 1;
        int end = n;
        
        while (start <= end) {
            int mid = start + (end - start)/2;
            if (!isBadVersion(mid)) {
               start = mid + 1;
            } else {
                firstBadVer = std::min(firstBadVer, mid);
                end = mid-1;
            }
        }
        return firstBadVer;
    }
    
    
    // Solution in discussed section that does not require you to take a variable like firstBadVersion
    // TC: O(logn)
    // SC: O(1)
    int firstBadVersion(int n) {
        int start = 1;
        int end = n;
        
        while (start < end) {
            int mid = start + (end - start)/2;
            if (!isBadVersion(mid)) {
               start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start; // returning start we are finding the first bad version.
    }
    
};
