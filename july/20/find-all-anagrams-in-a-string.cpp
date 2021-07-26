class Solution {
public:
    // For two strings to be Anagrams, they must be of same size and frequency of each char should be same in both.
    vector<int> findAnagrams(string s, string p) {
        int ssize = s.length();
        int psize = p.length();
        // when target string is greater, then it could not be anagram.
        if (psize > ssize) return {};
        
        // our result
        std::vector<int> indices; 
        
        // storing the target string p in an unordered_amp'
        std::unordered_map<char, int> map;
        for (char ch: p) {
            map[ch]++;
        }
        /* 
            p = 'abc' 
            map --- 
                    a - 1
                    b - 1
                    c - 1
        */
        
        // size of the map (created by p string)
        int counter = p.size(); // to maintain the comaprsion (take a example of dupliactes character)
        
        int beg = 0, end = 0; // pointer to s
        
        while (end < s.length()) {
            char ch = s[end];
            // if ch(take a character from end index) is present in map
            if (map.find(ch) != map.end()) {
                --map[ch]; // decreasing the frequency of ch by 1 because it's a match of char ch from string s to the element from p present in map
                if (map[ch] == 0) --counter;
            }
            ++end;
            
            while (counter  == 0) {
                char temp = s[beg];
                // here putting char ch at index beg so that when in next iteartion when we take element at end index we can check if they are same that means it's still an anagram
                // example ccbca and t = ccb
                // here at beg = 0 we add c to map, and in next ietartion at end = 3 we remove the character at index end which happens to be the same character that means we are still a valid anagram in next iteration
                if (map.find(temp) != map.end()) {
                    ++map[temp];
                    if (map[temp] > 0) {
                        ++counter;
                    }
                }
                if (end-beg == p.length()) indices.push_back(beg);
                ++beg;
            }
        }
        return indices;
    }
};
