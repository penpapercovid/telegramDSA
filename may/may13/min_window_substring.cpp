Problem : https://leetcode.com/problems/minimum-window-substring/

// 265 and 266 TC number are failing with this solution, needs more optimisation


// TC: O(slen*slen + tlen)
// More to learn 
// Very good questions
class Solution {
public:
    std::string substr(string &s, int j, int i) {
        std::string res("");
        for (int k = j; k <=i; ++k) {
            res += s[k];
        }
        return res;
    }
    string minWindow(string s, string t) {
        std::map<char, int> mapT; // to save the ferquency of each character in string 't'
        std::map<char, int> mapS;
        
        int lenS = s.size();
        int lenT = t.size();
        
        int i = -1, j = -1;
        std::string res(""); // final string
        
        // populating the frequency of each char in mapT
        // t = "ABC"
        for (auto const ch: t) {
            mapT[ch]++;
        }
        // After this step
        /*
            A-1
            B-1
            C-1
        */
        
        int desiredCnt = lenT; // number of character that are required
        int currCnt = 0; // variable to maintain char count that will ultimately be equal to desiredCnt and that string can be out potential answer
        
        while (true) {
            bool f1 = false;
            bool f2 = false;
            // acquire char by char until either the string is over or found a substring that has all the minimum chars to match the chars present in string t
            while (i < lenS-1 && currCnt < desiredCnt) {
                ++i;
                auto it = mapS.find(s[i]);
                if (it != mapS.end()) {
                    // s[i] present in map, increase freq by 1
                    ++mapS[s[i]];
                } else {
                    mapS.insert({s[i], 1});
                }
                
                if (mapS[s[i]] <= mapT[s[i]]) {
                    ++currCnt;
                }
                f1 = true;
            }
            
            
            // reach here hope you find atleast some string
            // There could be some characters that can be removed until it does not affects the found substring in above while loop
            while (j < i && currCnt == desiredCnt) {
                // potential result 
                ++j;
            
                std::string potentialResult = substr(s, j, i);// both j and i inclusive
                if (res.length() == 0 || res.length() > potentialResult.length()) {
                    res = potentialResult; 
                }
                
                auto it = mapS.find(s[j]);
                if (it->first == 1) {
                    mapS.erase(it);
                } else {
                    --(it->second);
                }
                
                if (mapS[s[j]] < mapT[s[j]]) {
                    --currCnt;
                }
                    
                f2 = true;
            }
            
            if (!f1 && !f2) {
                break;
            }                      
        }        
        return res;
    }
};
// Very Easy Explanation: https://www.youtube.com/watch?v=e1HlptlipB0&t=1030s&ab_channel=Pepcoding
//
//
//
// Template to solve most substring problem
// https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
