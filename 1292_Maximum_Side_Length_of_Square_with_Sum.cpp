class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));

        // 1. Build the 2D Prefix Sum matrix
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + mat[i-1][j-1];
            }
        }

        int maxSide = 0;
        // 2. Iterate through each possible bottom-right corner (i, j)
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // Check if a square of side (maxSide + 1) exists ending at (i, j)
                int nextSide = maxSide + 1;
                if (i >= nextSide && j >= nextSide) {
                    // Formula to get sum of square ending at (i, j) with side 'nextSide'
                    int currentSum = pref[i][j] - pref[i - nextSide][j] - pref[i][j - nextSide] + pref[i - nextSide][j - nextSide];
                    
                    if (currentSum <= threshold) {
                        maxSide = nextSide; // Found a larger square!
                    }
                }
            }
        }

        return maxSide;
    }
};
