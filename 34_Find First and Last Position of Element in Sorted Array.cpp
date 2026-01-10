class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        
        // Edge case: empty array
        if (nums.empty()) return result;

        // Pass 1: Find the first occurrence
        result[0] = findBound(nums, target, true);
        
        // If the target wasn't found at all, no need to search for the end
        if (result[0] == -1) return result;
        
        // Pass 2: Find the last occurrence
        result[1] = findBound(nums, target, false);
        
        return result;
    }

private:
    // Helper function to perform binary search
    // isFirst: true to find the first occurrence, false to find the last
    int findBound(const vector<int>& nums, int target, bool isFirst) {
        int left = 0;
        int right = nums.size() - 1;
        int boundIndex = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                boundIndex = mid; // Record the potential answer
                
                if (isFirst) {
                    right = mid - 1; // Narrow search to the left
                } else {
                    left = mid + 1;  // Narrow search to the right
                }
            } 
            else if (nums[mid] < target) {
                left = mid + 1;
            } 
            else {
                right = mid - 1;
            }
        }
        return boundIndex;
    }
};