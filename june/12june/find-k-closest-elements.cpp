Problem Link: https://leetcode.com/problems/find-k-closest-elements/

class Solution {
public:
    // Method 1: Using extra space
    // The main logic is check for every number for its distance from x and sort the numbers by this criteria abs(x-num) where num is every element in array

    // 1. Create an extra array of size of arr and copy all elements.
    // 2. Sort the new array by using comparator the comparison key is abs(x-num).
    // 3. After sorting the first k elemnent will be closest to x, earse all the elements after k.
    // 4. Sort the array again

    /*
        arr = [1,2,3,4,5] k = 4 & x = 3
        new _arr = [1,2,3,4,5] --- (1)
        after sorting new_arr = [3, 2, 4, 1, 5] ---- (2)
        after removing elements erase all elements after k, new_arr = [3, 2, 4, 1]
        sorting the left array [1,2,3,4]


        another example
        arr [10, 20, 30, 40, 50, 60] x = 45 & k = 3
        new _arr = [10, 20, 30, 40, 50, 60] --- (1)
        after sorting new_arr = [40, 50, 30, 60, 10] ---- (2)
        after removing elements erase all elements after k, new_arr = [40, 50, 30]
        sorting it back to item so item move to its correct position new_arr [30,40,50]


    */
    void print(const std::vector<int> &arr) {
        for (auto &i : arr) std::cout << i << ' ';
        std::cout << std::endl;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        // step 1
        std::vector<int> result;
        for (auto &i: arr) result.push_back(i);

        auto comparator = [&] (int num1, int num2) {
            return abs(x - num1) < abs(x -num2);
        };

        // struct { // cannot access x in struct
        //     bool operator()(int num1, int num2) const {
        //         return abs(x - num1) - abs(x -num2);
        //     }
        // } comparator;

        // step 2
        std::sort(result.begin(), result.end(), comparator);

        // step 3
        result.erase(result.begin() + k, result.end());

        // step 4
        std::sort(result.begin(), result.end());
        std::cout << result.size() << std::endl;
        return result;
    }


};





