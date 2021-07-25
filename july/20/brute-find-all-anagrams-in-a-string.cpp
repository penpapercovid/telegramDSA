// Just for testing purpose, I used sort technique. To check if two strings are valid anagrams use map
    bool isValidAnagrams(std::string &s, std::string &p) {
        std::sort(s.begin(), s.end());
        std::sort(p.begin(), p.end());
        return s.compare(p) == 0;
    }
    // Brute Force O(N^3P) It will give TLE.
    // TLE: 21th test case.
    // Till 20th the test cases were passing.
    // In interviews, one must come atleast with brute force. You will be rejected even with brute force but it will save you from embarrassment.
    // vector<int> findAnagrams(string s, string p) {
    //     std::vector<int> indices;
    //     int n = s.size();
    //     for (int i = 0; i < n; ++i) {
    //         for (int j = 1; j <= n-i; ++j) {
    //             std::string substring = s.substr(i,j);
    //             if (p.size() == substring.size() && isValidAnagrams(substring, p)) {
    //                 indices.push_back(i);
    //             } 
    //         }
    //     }
    //     return indices;
    // }
    
    bool isValidAnagram(std::string &potentialAna, std::unordered_map<char, int> pMap) {
        for (char ch: potentialAna) {
            auto it = pMap.find(ch);
            if (it == pMap.end()) return false;
            else {
                if (it->second == 1) pMap.erase(it);
                else --(it->second);
            }
        }
        return pMap.empty();
    }
    
    // Method 1: Some Improvement in Brute Force
    // Time Complexity: O(NP^2)
     vector<int> findAnagrams(string s, string p) {
         if (p.length() > s.length()) return {};
         std::vector<int> indices;
         int sSize = s.size(); // length of s
         std::unordered_map<char, int> pMap;
         // frequency map of p
         for (char ch: p) 
             pMap[ch]++;
         
         int pSize = p.size();
         for (int i = 0; i < sSize; ++i) {
             int j = pSize;
             std::string potentialAna = s.substr(i, j);
             if (isValidAnagram(potentialAna, pMap)) 
                 indices.push_back(i);
         }
         
         return indices;
     }
};
