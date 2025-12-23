class Solution {
private:
    // 0 and 1 map to nothing. Index 2 maps to "abc", etc.
    const vector<string> keypad = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(const string& digits, int index, string& current, vector<string>& result) {
        // Base Case: If the current string length equals the digits length
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        // Get the integer value of the current digit char (e.g., '2' -> 2)
        int digit = digits[index] - '0';
        const string& letters = keypad[digit];

        // Iterate through valid letters for this digit
        for (char letter : letters) {
            current.push_back(letter);           // Choose
            backtrack(digits, index + 1, current, result); // Explore
            current.pop_back();                  // Un-choose (Backtrack)
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string> result;
        string current;
        
        // Optional: Reserve memory to avoid reallocations. 
        // Max combinations is 4^4 = 256. 
        // result.reserve(pow(4, digits.size())); 

        backtrack(digits, 0, current, result);
        return result;
    }
};