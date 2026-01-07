class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }

private:
    Node* build(vector<vector<int>>& grid, int r, int c, int size) {
        if (isAllSame(grid, r, c, size)) {
            // If all values are the same, this is a leaf node
            return new Node(grid[r][c] == 1, true);
        }

        // Otherwise, it's an internal node; divide into 4 quadrants
        int half = size / 2;
        Node* topLeft = build(grid, r, c, half);
        Node* topRight = build(grid, r, c + half, half);
        Node* bottomLeft = build(grid, r + half, c, half);
        Node* bottomRight = build(grid, r + half, c + half, half);

        // Current node's value can be anything (true/false) if isLeaf is false
        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }

    bool isAllSame(vector<vector<int>>& grid, int r, int c, int size) {
        int firstVal = grid[r][c];
        for (int i = r; i < r + size; i++) {
            for (int j = c; j < c + size; j++) {
                if (grid[i][j] != firstVal) return false;
            }
        }
        return true;
    }
};