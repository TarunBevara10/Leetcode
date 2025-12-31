class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        // Optimization: Use boolean arrays to track occupied lines.
        // Size for diagonals is 2*n because max sum is (n-1)+(n-1).
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n, false); // For row - col
        vector<bool> diag2(2 * n, false); // For row + col
        
        backtrack(0, n, count, cols, diag1, diag2);
        return count;
    }

private:
    void backtrack(int row, int n, int& count, 
                   vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
        // Base case: If we've placed queens in all rows (0 to n-1)
        if (row == n) {
            count++;
            return;
        }

        // Try placing a queen in every column of the current row
        for (int col = 0; col < n; ++col) {
            // Calculate diagonal IDs
            int d1 = row - col + n; // Shift by n to ensure positive index
            int d2 = row + col;

            // Check if this position is under attack
            if (cols[col] || diag1[d1] || diag2[d2]) {
                continue;
            }

            // Place Queen (Mark constraints)
            cols[col] = true;
            diag1[d1] = true;
            diag2[d2] = true;

            // Move to next row
            backtrack(row + 1, n, count, cols, diag1, diag2);

            // Backtrack (Unmark constraints)
            cols[col] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }
};