class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(n, k, 1, current, result);
        return result;
    }

private:
    void backtrack(int n, int k, int start, vector<int>& current, vector<vector<int>>& result) {
        // Base case: if combination is the correct size, add to result
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        // Iterate from 'start' to 'n'.
        // Optimization: Limit the loop. We only iterate if there are enough 
        // remaining elements to fill the combination to size k.
        // limit = n - (remaining_needed) + 1
        int remaining_needed = k - current.size();
        
        for (int i = start; i <= n - remaining_needed + 1; ++i) {
            current.push_back(i);        // Choose i
            backtrack(n, k, i + 1, current, result); // Explore with next numbers
            current.pop_back();          // Un-choose i (Backtrack)
        }
    }
};