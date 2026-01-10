class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // Check if the left half is sorted
            if (nums[left] <= nums[mid]) {
                // If target is in the left sorted portion
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    // Target must be in the right half
                    left = mid + 1;
                }
            }
            // Otherwise, the right half must be sorted
            else {
                // If target is in the right sorted portion
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    // Target must be in the left half
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};