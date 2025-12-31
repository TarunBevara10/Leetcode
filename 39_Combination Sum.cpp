class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        // Sorting enables the optimization (pruning) inside the loop
        sort(candidates.begin(), candidates.end());
        
        backtrack(candidates, target, 0, current, result);
        return result;
    }

private:
    void backtrack(vector<int>& candidates, int remaining, int start, vector<int>& current, vector<vector<int>>& result) {
        // Base case: Perfect match found
        if (remaining == 0) {
            result.push_back(current);
            return;
        }

        // Iterate starting from 'start' to avoid duplicate sets (e.g., [2,3] vs [3,2])
        for (int i = start; i < candidates.size(); ++i) {
            // Optimization: Since array is sorted, if current number > remaining,
            // no subsequent number can validly sum to target.
            if (candidates[i] > remaining) {
                break; 
            }

            current.push_back(candidates[i]);
            
            // KEY CHANGE: Pass 'i' (not i + 1) because we can reuse the current number.
            backtrack(candidates, remaining - candidates[i], i, current, result);
            
            // Backtrack
            current.pop_back();
        }
    }
};