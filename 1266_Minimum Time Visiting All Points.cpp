class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int totalTime = 0;
        
        // Iterate through the points, stopping at the second to last point
        for (int i = 0; i < points.size() - 1; ++i) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            int x2 = points[i+1][0];
            int y2 = points[i+1][1];
            
            // Calculate absolute differences
            int deltaX = abs(x2 - x1);
            int deltaY = abs(y2 - y1);
            
            // The time to travel between two points is the max of the differences
            totalTime += max(deltaX, deltaY);
        }
        
        return totalTime;
    }
};