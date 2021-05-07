// Trie DS
// Resource: https://www.geeksforgeeks.org/trie-insert-and-search/
//
//
//
//
// structure for the TrieNode
#include <iostream>
#include <string>
#include <vector>

struct TrieNode {
    bool isAWord; // marker for a word present in dictionary.
    struct TrieNode *arr[26]; // 26 is for number of alphabets
};

class Trie {
public: 
    Trie();
    ~Trie() = default;
    bool search(const std::string &word) const;
    void insert(const std::string &word);
    bool remove(const std::string &word);
    void traverse() const;
private:
    TrieNode *m_root;
};

Trie::Trie() :m_root(new TrieNode()){
    // initialing root
    m_root->isAWord = false;
    for (int i = 0; i < 26/*total alphaber*/; ++i) {
        m_root->arr[i] = nullptr;
    }
}

// TC: O(length(word))
bool Trie::search(const std::string &word) const {
    TrieNode *node = m_root;
    for (char ch: word) {
        if (node->arr[ch - 'a'] == nullptr) { // ch does not exist
            return false;
        }
        node = node->arr[ch - 'a']; // move to child
    }
    return node && node->isAWord;
}

// TC: O(length(word))
void Trie::insert(const std::string &word) {
    TrieNode *node = m_root;
    for (char ch: word) {
        if (node->arr[ch - 'a'] == nullptr) { // character is not present in trie, create a new node 
            node->arr[ch - 'a'] = new TrieNode();
        }
        node = node->arr[ch -'a']; // move to child
    }
    node->isAWord = true;
}

// TC: O(length(word))
// pending
bool Trie::remove(const std::string &word) {
       
}

void traverseUtility(TrieNode* root, std::string word, int wordIndex = 0) {
}

// TC: O(No of words in dictinary * M),  M - lenght of the longest string
// pending
void Trie::traverse() const {
}

int main() {
    Trie *trie = new Trie();
    const std::vector<std::string> words = {"hello", "hell", "there", "is", "any", "one", "available", "for", "help"};
    for (const std::string &word: words) {
        trie->insert(word);
    }
    trie->traverse();
    trie->search("hello") ? std::cout << "P\n" : std::cout << "NP\n"; 
    trie->search("hell") ? std::cout << "P\n" : std::cout << "NP\n"; 
    trie->search("there") ? std::cout << "P\n" : std::cout << "NP\n";
    trie->search("thereg") ? std::cout << "P\n" : std::cout << "NP\n";
    trie->search("available") ? std::cout << "P\n" : std::cout << "NP\n";
    trie->search("availabl") ? std::cout << "P\n" : std::cout << "NP\n";
    return 0;
}
