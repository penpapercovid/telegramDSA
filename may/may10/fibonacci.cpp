//Problem Link: https://leetcode.com/problems/fibonacci-number/
//


class Solution {
public:
    // Method 0: By Recursion
    // By definition: F(N) = F(N-1) + F(N-2), for N >= 2
    // F(0) = 0, F(1) = 1
    // TC: O(2^N)
    // Brute Force
     int fib(int n) {
         if (n == 0 || n == 1) {
             return n;
         }
         return fib(n-1) + fib(n-2);
     }

    /*  Understanding the time complexity
              fib(n)
              /    \
           fib(n-1) fib(n-2)
           For each n there will two branches
           TC: O(2^n)
    */

    /*
        Let's say n = 5
                 fib(5)
                /       \
            fib(4)        fib(3)
            /     \          /      \
          fib(3)   fib(2)    fib(2)  fib(1)
          /   \      / \     /  \
    fib(2) fib(1)  fib(1) fib(0) .....

Tree can be drawn in this pattern.
It has overlapping subproblem as you can see in the recursion tree there are nodes like fib(3) fib(2) which are redundant. We do not need to recompute them if we save these value in some data structure and retrieve it during recomputation of same sub problem.
This paradigm of problem is known as dynamic programming. Any problem qualify for DP if it has Overlapping SubProblem and Optimal Substructure.

-------------------------------------------------------------------------------------------------------------------
    Key Point to solve any dynamic problem:
    1. Write the recursion to solve the problem.
    2. Identify if it is indeed a DP problem.
    3. If so, use either bottom or top down approach.
--------------------------------------------------------------------------------------------------------------------
    Top Down Approach (Memoization): Simpler than Botton Up

       1. The memoized program for a problem is similar to the recursive version with a small modification that it looks into a lookup table before computing solutions.
       2. It initialises the lookup table with all values as false, -1, or any marker from which we can know that we have not solved this subproblem yet or have solved it.
       3. If already solved the subproblem use it.


--------------------------------------------------------------------------------------------------------------------
    */
    // Method 1: Using Top Down Approach (memoization)
    // TC: O()
    // SC: O(N)
     int fibUtil(int n, int dp[]) {
         if (dp[n] != -1) {
             return dp[n];
         }
         if (n == 0 || n == 1) {
             dp[n] = n;
         } else {
             dp[n] = fibUtil(n-1, dp) + fibUtil(n-2, dp);
         }
         return dp[n];
     }

     int fib(int n) {
         int dp[n+1];
         memset(dp, -1, sizeof(dp));
         fibUtil(n, dp);
         return dp[n];
     }

--------------------------------------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------------------------------------
    // Method 2: Using Bottom Up Approach (tabulation)
    // TC: O(N)
    // SC: O(N)
    int fib(int n) {
         // base condtion
         if (n == 0 || n == 1) {
             return n;
         }
         int dp[n+1];
         memset(dp, -1, sizeof(dp));
         dp[0] = 0;
         dp[1] = 1;
         for (int i = 2; i<= n; ++i) {
             dp[i] = dp[i-1] + dp[i-2];
         }
         return dp[n];
     }

--------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------
    // Method 3: Without using table
    // TC: O(N)
    // SC: O(1)
    int fib(int n) {
        // base condition
        if (n == 0 || n == 1) {
            return n;
        }

        int a = 0; // fib(0)
        int b = 1; // fib(1)
        int c = 0; // fib we are calculating
        for (int i = 2; i <=n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
--------------------------------------------------------------------------------------------------------------------
};
