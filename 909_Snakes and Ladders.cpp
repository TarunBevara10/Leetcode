class Solution {
public:
    // Helper function to convert square number 'curr' (1-based) to (row, col)
    pair<int, int> getCoordinates(int curr, int n) {
        // Calculate row index from the bottom (0-indexed)
        int rowFromBottom = (curr - 1) / n;
        
        // Calculate actual row index in 2D array (0 is top)
        int r = n - 1 - rowFromBottom;
        
        // Calculate column index
        // Even rows from bottom (0, 2...) go Left -> Right
        // Odd rows from bottom (1, 3...) go Right -> Left
        int c = (curr - 1) % n;
        if (rowFromBottom % 2 == 1) {
            c = n - 1 - c;
        }
        
        return {r, c};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int target = n * n;
        
        // Queue for BFS: stores {current_square, moves_so_far}
        queue<pair<int, int>> q;
        q.push({1, 0});
        
        // Visited array to prevent cycles and redundant work
        // Size is n*n + 1 to accommodate 1-based indexing
        vector<bool> visited(n * n + 1, false);
        visited[1] = true;
        
        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();
            
            int currSquare = current.first;
            int moves = current.second;
            
            // Try all 6 dice rolls
            for (int i = 1; i <= 6; ++i) {
                int nextSquare = currSquare + i;
                
                // Don't roll off the board
                if (nextSquare > target) break;
                
                // Check if this square has a snake or ladder
                pair<int, int> pos = getCoordinates(nextSquare, n);
                int r = pos.first;
                int c = pos.second;
                
                int destination = nextSquare;
                
                // If board has a value != -1, we MUST take the jump
                if (board[r][c] != -1) {
                    destination = board[r][c];
                }
                
                // If we reached the end
                if (destination == target) return moves + 1;
                
                // If not visited, add to queue
                if (!visited[destination]) {
                    visited[destination] = true;
                    q.push({destination, moves + 1});
                }
            }
        }
        
        // If queue empties and we never reached target
        return -1;
    }
};