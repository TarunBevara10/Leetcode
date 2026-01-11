class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        // Loop until the search space is reduced to one element
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // If mid is greater than the rightmost element, 
            // the min is strictly to the right.
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            // If mid is less than or equal to the rightmost, 
            // the min is at mid or to the left.
            else {
                right = mid;
            }
        }
        
        // left and right converge to the minimum element
        return nums[left];
    }
};