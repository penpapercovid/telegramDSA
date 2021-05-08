class Solution {
public:
    // The most basic approach lies in the definition of the Anagrams
    // Anagrams is a word or phrase formed by rearranging the letters of a different word or phrase
    // eg [eat, ate] when sorted [aet, aet] same
    
    // Algorithm:
    // 1. store the vector of string into pair of string and its index.
    // 2. sort the each pair of value ie pair.first 
    // 3. sort the vector of pair of strings
    // 4. Iterate over the vector of pair of strings and based on same value store them in a map.
    // 5. Based on second valud of map ie index of strs get the value from strs and them into res.
    // TC: 
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        std::vector<std::vector<std::string>> res;
        
        std::vector<std::pair<std::string, int>> pairOfString;
        
        int i = 0; // index
        // eg strs -> ["eat","tea","tan","ate","nat","bat"]
        // --------------------------------------------------------
        //    FIRST STEP - TC-O(N)
        // --------------------------------------------------------
        
        for (auto const &word: strs) {
            pairOfString.push_back({word, i});
            ++i;
        }
        
        // after insertion pairOfString would look like
        // [(eat, 0),(tea, 1), (tan, 2), (ate, 3), (nat, 4), (bat, 5)]
        
        // sort the pair.first for each index
        // --------------------------------------------------------
        //    SECOND STEP - TC-O(NMlogM)
        // --------------------------------------------------------
        for (auto &pair: pairOfString) {
            auto &word = pair.first;
            std::sort(word.begin(), word.end());
        }
        
        
        // after sorting pairOfString would look like
        // [(aet, 0),(aet, 1), (ant, 2), (aet, 3), (ant, 4), (abt, 5)]
        
        // sort the vector
        // --------------------------------------------------------
        //    THIRD STEP TC-O(NlogN+M)
        // --------------------------------------------------------
        std::sort(pairOfString.begin(), pairOfString.end(), [=](const auto &word1, const auto &word2) -> bool {
                 return word1 < word2;
        });
        
        // after sorting vector, it would look like
        // [(abt, 5), (aet, 0),(aet, 1), (aet, 3), (ant, 2), (ant, 4)]
        
        
        // --------------------------------------------------------
        //    FOURTH STEP - TC-O(N)
        // --------------------------------------------------------
        std::map<std::string, std::vector<int>> map;
        for (auto const &pair: pairOfString) {
            auto &word = pair.first;
            int index = pair.second;
            auto it = map.find(word);
            if (it == map.end()) { // word not existed in map
                map.insert({word, {index}});
            } else {
                auto &vec = it->second;
                vec.push_back(index);
            }
        }
        
        // the map should look like
        /* [
                aet  ->  [0,3,4]
                ant  ->  [2, 4]
                abt  ->  [5]
           ]       
        */ 
        
        
        // --------------------------------------------------------
        //    FIFTH STEP - TC-O(N)
        // --------------------------------------------------------              
        for (auto it: map) {
            auto &vec = it.second;
            std::vector<std::string> anag;
            for (auto index: vec) {
                anag.push_back(strs[index]); // retrieveing value from strs original array
            } 
            res.push_back(anag);
        }
        
        
        return res;
    }
};
