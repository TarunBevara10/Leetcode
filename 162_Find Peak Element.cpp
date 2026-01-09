class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // Compare mid with its right neighbor
            if (nums[mid] < nums[mid + 1]) {
                // We are on an upward slope.
                // The peak must be to the right of mid.
                left = mid + 1;
            } else {
                // We are on a downward slope (or mid is the peak).
                // The peak is either at mid or to the left.
                right = mid;
            }
        }

        // When left == right, we have found a peak
        return left;
    }
};