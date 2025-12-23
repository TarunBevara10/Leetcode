class Solution {
private:
    // 1. Manual Trie Implementation
    struct TrieNode {
        TrieNode* children[26];
        string* word; // Pointer to the word string if this node is an end

        TrieNode() {
            word = nullptr;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    void insert(TrieNode* root, string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->word = &word; // Store pointer to the input string
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, vector<string>& result) {
        // Base case: Check bounds or if visited ('#')
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] == '#') {
            return;
        }

        char ch = board[r][c];
        int idx = ch - 'a';

        // Optimization: If current char doesn't exist in Trie path, stop.
        if (node->children[idx] == nullptr) {
            return;
        }

        // Move to the child node
        node = node->children[idx];

        // Check if a word ends here
        if (node->word != nullptr) {
            result.push_back(*node->word);
            node->word = nullptr; // Deduplicate: Ensure we don't add this word again
        }

        // Mark as visited
        board[r][c] = '#';

        // Explore neighbors (Up, Down, Left, Right)
        dfs(board, r + 1, c, node, result);
        dfs(board, r - 1, c, node, result);
        dfs(board, r, c + 1, node, result);
        dfs(board, r, c - 1, node, result);

        // Backtrack: Restore the character
        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        
        // Build Trie
        for (string& w : words) {
            insert(root, w);
        }

        vector<string> result;
        int rows = board.size();
        int cols = board[0].size();

        // Start DFS from every cell
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dfs(board, i, j, root, result);
            }
        }

        return result;
    }
};