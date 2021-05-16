Problem Link:https://leetcode.com/problems/powx-n/

class Solution {
public:
-------------------------------------------------------------------------    
METHOD1
    // Brute Force
    // TC: O(N)
    // SC: O(1)
    double myPow(double x, int n) {
        double ans = 1; // answer to return
        
        // if n is negative just reciprocal x and make n positive
        if (n < 0) {
            n = -n;
            x = 1/x;
        }
        
        for (int i = 1; i <= n; ++i) {
            ans = ans * x;
        }
        return ans;
    }
-------------------------------------------------------------------------    
METHOD2
    double myPowUtil(double x, long long n) {
        if (n == 0) return 1;
        double midVal = myPowUtil(x, n/2);
        if (n % 2 == 0) return midVal * midVal;
        else return x * midVal * midVal;
            
    }
    
    // TC: O(logn)
    // SC: O(logn)
    double myPow(double x, int n) {
        // n is negative, just reciprocate x and replace n by -n, simple mathematics followed
        long long N  = n; // to handle case x =1.00000 n = -2147483648
        if (n < 0) {
            x = 1.0/x;
            N = -N;
        }        
        return myPowUtil(x, N);
    }
    
------------------------------------------------------------------------------- METHOD3
   // Using Iterative Method


};
