#include <iostream>
#include <unordered_map>
#include <string>

// TrieNode class
class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

// Trie class
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    bool search(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return node->isEndOfWord;
    }

    bool startsWith(const std::string& prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("hello");
    trie.insert("world");

    std::cout << std::boolalpha;
    std::cout << "Search for 'hello': " << trie.search("hello") << std::endl;
    std::cout << "Search for 'world': " << trie.search("world") << std::endl;
    std::cout << "Search for 'hell': " << trie.search("hell") << std::endl;
    std::cout << "Starts with 'he': " << trie.startsWith("he") << std::endl;

    return 0;
}
