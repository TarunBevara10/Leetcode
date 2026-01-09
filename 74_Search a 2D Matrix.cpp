class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Define the range for the virtual 1D array
        int left = 0;
        int right = m * n - 1;
        
        while (left <= right) {
            // Standard binary search mid calculation
            int mid = left + (right - left) / 2;
            
            // Map 1D mid index to 2D matrix coordinates
            int mid_val = matrix[mid / n][mid % n];
            
            if (mid_val == target) {
                return true;
            } else if (mid_val < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};