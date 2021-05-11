// Problem Link: https://leetcode.com/problems/group-anagrams/
//
//
//
class Solution {
public:
    // Method 1: Improvement in approach of group_anagrams_worst_sol.cpp (Approach is exactly same)
    // TC: Say total size of vector is N and sorting takes for size M O(MlogM)
    // O(N(MlogM)) considering M the largest string
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> map;
        vector<vector<string>> res;
        for (auto eachWord: strs) {
            std::string word = eachWord;
            std::sort(word.begin(), word.end());
            map[word].push_back(eachWord);
        }
        // Let's say strs -> ["eat","tea","tan","ate","nat","bat"]
        // After this step the map would look like
        /*
            aet -> [eat, tea, ate]
            ant -> [tan, nat]
            abt -> [bat]
        
        */ 
        
        for (auto const &iter: map) {
            res.push_back(iter.second);        
        }        
        return res;  
    }
    
    
    // Method 2 : can be improved with counting sort 
    // TC: O(NM) N is size of strs and M is length of longest string present.
    // pending
};


