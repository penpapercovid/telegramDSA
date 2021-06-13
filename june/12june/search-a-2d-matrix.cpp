Problem Link: https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    // Algorithm:
    /*
        In any questions we see words like sorted the first thing that should comes to our mind is Binary Search
        Now, how we will apply it ?

        1. The 2D matrix can also of 1D matrix even in actual also the 2D matrix are stored as 1D only
        2. [
              1    3    5   7
              10   11  16   20
              23   30  34   60
            ]

            is actually 1D in actual memory representation see Pg338 of Cracking the Coding Interview
        3. So, you can think of this 2d array is 1D and start applying binary serach

        Main Gist: From which index I will start working ?
                   Start apply binary search on index [0][col-1] or [row-1][0]

        ***************************************
        These are the two indice {0, col-1} or {row-1, 0} in which down value increases and left decreases and up decreases and right increases respectively.
        ***************************************

    */

    Time Complexity: O(row + col) -- confusion
    Space Compelxity: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowInMatrix = matrix.size();
        // relaying that atleast one row is present
        int colInMatrix = matrix[0].size();

        // indices for iteration on the given matrix
        int i = 0;
        int j = colInMatrix-1;

        // iterating over the matrix
        while (i < rowInMatrix && j >=0) {
            // if target is found
            if (matrix[i][j] == target) return true;
            // if target is less than current indices{i, j} in process that means the element could be found in indices{i, j-1} --- (2)
            else if (matrix[i][j] > target) --j;
            // vice versa of (2)
            else ++i;
        }

        // reached here => target is not present in the matrix.
        return false;
    }

----------------------------------------------------------------------------------------------------------------------------

    // Method 2 : Mention in Discussion section
    // As I have told you that 2D array is actually a 1D array in memory

    /*
      m = 3 and n = 4
       [
          1    3    5   7       0                               9      m*n-1
          10   11  16   20  => [1, 3, 5, 7, 10, 11, 16, 20, 23, 30, 34, 60]
          23   30  34   60
        ]
---------------------------------------------------------------------------------------------------------------------

       1.  matrix[i][j] =  array[i*n + j] where n is number of column
       2.  array[i] = matrix[i/n][i%n] where n is number of column


        e.g

        1. matrix[2][1](value 30) = array[2*4 + 1] = array[9] = 30

        2. array[9](value 30) = matrix[9/4][9%4] = matrix[2][1] = 30


---------------------------------------------------------------------------------------------------------------------

    */
    Time Complexity : O(logm + logn)
    Space Complexity: O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowInMatrix = matrix.size();
        // relaying that atleast one row is present
        int colInMatrix = matrix[0].size();

        int low = 0;
        int high = rowInMatrix * colInMatrix - 1;

        // apply standard binary serach
        while (low <= high) {
            int midIdx = low + (high - low)/2;
            int midItem = matrix[midIdx / colInMatrix][midIdx % colInMatrix];
            // if middle element is the target
            if (midItem == target) {
                return true;
            }
            // middle element is greater than target
            else if (midItem > target)  {
                high = midIdx - 1;
            }  else {
                low = midIdx + 1;
            }
        }
        return false;
    }
};

