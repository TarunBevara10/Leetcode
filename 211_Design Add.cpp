class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root;

    // Helper function for DFS search
    bool searchHelper(string& word, int index, TrieNode* curr) {
        // Base Case: If we have reached the end of the word
        if (index == word.length()) {
            return curr->isEnd;
        }

        char c = word[index];

        if (c == '.') {
            // If character is '.', check all possible non-null children
            for (int i = 0; i < 26; i++) {
                if (curr->children[i] != nullptr) {
                    // If any path returns true, the search is successful
                    if (searchHelper(word, index + 1, curr->children[i])) {
                        return true;
                    }
                }
            }
            // If no path worked
            return false;
        } else {
            // Standard character match
            int childIdx = c - 'a';
            if (curr->children[childIdx] == nullptr) {
                return false;
            }
            // Recurse to the next character
            return searchHelper(word, index + 1, curr->children[childIdx]);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};