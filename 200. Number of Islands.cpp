class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        int islandCount = 0;
        
        // Iterate through every cell in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If we find land, it's a new island
                if (grid[i][j] == '1') {
                    islandCount++;
                    // Start DFS to "sink" the entire island
                    dfs(grid, i, j);
                }
            }
        }
        
        return islandCount;
    }

private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Base case for recursion:
        // 1. Check bounds (r < 0, r >= m, etc.)
        // 2. Check if it's water (grid[r][c] == '0')
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == '0') {
            return;
        }
        
        // Mark the current cell as visited by turning it into water ('0')
        // This prevents us from counting this piece of land again
        grid[r][c] = '0';
        
        // Recursively visit all 4 adjacent neighbors (Up, Down, Left, Right)
        dfs(grid, r + 1, c); // Down
        dfs(grid, r - 1, c); // Up
        dfs(grid, r, c + 1); // Right
        dfs(grid, r, c - 1); // Left
    }
};