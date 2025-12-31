class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(n, 0, 0, current, result);
        return result;
    }

private:
    void backtrack(int n, int open, int close, string& current, vector<string>& result) {
        // Base case: String is fully built (length 2*n)
        if (current.length() == n * 2) {
            result.push_back(current);
            return;
        }

        // Rule 1: Can we add an open bracket?
        if (open < n) {
            current.push_back('(');
            backtrack(n, open + 1, close, current, result);
            current.pop_back(); // Backtrack
        }

        // Rule 2: Can we add a close bracket?
        if (close < open) {
            current.push_back(')');
            backtrack(n, open, close + 1, current, result);
            current.pop_back(); // Backtrack
        }
    }
};