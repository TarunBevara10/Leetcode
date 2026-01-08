class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            // Prevent potential integer overflow compared to (left + right) / 2
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid; // Target found
            } else if (nums[mid] < target) {
                left = mid + 1; // Target is in the right half
            } else {
                right = mid - 1; // Target is in the left half
            }
        }
        
        // If the loop finishes, 'target' was not found.
        // 'left' is now at the index where 'target' would be inserted 
        // to maintain order.
        return left;
    }
};