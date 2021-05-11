// Problem Link:https://leetcode.com/problems/string-to-integer-atoi/
//
//

// TC: O(length of string)
// SC: O(1)
class Solution {
public:
    bool isNumber(char ch) {
        return ch >= '0' && ch <= '9';
    }
    int myAtoi(string s) {
        int res = 0;
        int length = s.size();

        // empty string
        if (length == 0) {
            return 0;
        }

        bool isNegativeInteger = false;
        // check if string has leading spaces
        int i = 0;
        while (s[i] == ' ') ++i;

        // if all whitespaces only
        if (i == length) return 0;

        // check if a negative integer
        if (s[i] == '-') {
            isNegativeInteger = true;
            ++i;
        } else if (s[i] == '+') { // check if first char is a positive integer
            ++i;
        }
        // check if first char after ' ' and '-' is actually a number or not
        if (!isNumber(s[i])) {
            return 0;
        }
        // FYI: INT_MAX = 2147483647
        // check for overflow
        while (isNumber(s[i])) {
            // res > INT_MAX/10 suggests that future res when multiplied by 10 is going to surpass INT_MAX
            // res == INT_MAX/10 i.e curr res value is 214748364. Now if last digit is > 7 that means res is going 214748364 * 10 + > 7 that will surpass the INT_MAX value
            // If res == INT_MAX/10 and last char is atmost 7 then res is going to be either INT_MAX or INT_MIN and that is within range.
            if ((res > INT_MAX/10) || res == INT_MAX/10 && (s[i] - '0') > 7) {
                return (isNegativeInteger) ? INT_MIN: INT_MAX;
            }
            res = res * 10 + (s[i] - '0') ;
            ++i;
        }
        return isNegativeInteger ? -res : res;
    }
};
