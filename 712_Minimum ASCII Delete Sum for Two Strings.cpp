class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        
        // dp[i][j] stores the minimum ASCII sum of deleted characters 
        // to make s1[0...i-1] and s2[0...j-1] equal.
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        // Base Case 1: If s2 is empty, we must delete everything from s1
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = dp[i-1][0] + s1[i-1];
        }

        // Base Case 2: If s1 is empty, we must delete everything from s2
        for (int j = 1; j <= m; ++j) {
            dp[0][j] = dp[0][j-1] + s2[j-1];
        }

        // Fill the DP table
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s1[i-1] == s2[j-1]) {
                    // Characters match: no new deletion cost
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    // Mismatch: delete char from s1 OR delete char from s2
                    // Pick the option that results in the lower total cost
                    int delete_s1 = dp[i-1][j] + s1[i-1];
                    int delete_s2 = dp[i][j-1] + s2[j-1];
                    dp[i][j] = min(delete_s1, delete_s2);
                }
            }
        }

        return dp[n][m];
    }
};