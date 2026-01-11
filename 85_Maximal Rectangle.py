#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;
        
        // Iterate through every row
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // Update histogram heights
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            
            // Calculate max area for the current row's histogram
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        
        return maxArea;
    }

private:
    // Helper function: Solves "Largest Rectangle in Histogram"
    // Uses a Monotonic Increasing Stack
    int largestRectangleArea(const vector<int>& heights) {
        stack<int> s;
        int maxA = 0;
        int n = heights.size();
        
        // We iterate up to n to push a '0' height at the end, 
        // forcing the stack to empty and calculate all remaining areas.
        for (int i = 0; i <= n; ++i) {
            int currentHeight = (i == n) ? 0 : heights[i];
            
            // While the current bar is shorter than the bar at stack top,
            // we found the right boundary for the bar at stack top.
            while (!s.empty() && currentHeight < heights[s.top()]) {
                int height = heights[s.top()];
                s.pop();
                
                // Width is distance between current index (right boundary)
                // and the new top of stack (left boundary).
                int width = s.empty() ? i : i - s.top() - 1;
                
                maxA = max(maxA, height * width);
            }
            s.push(i);
        }
        
        return maxA;
    }
};