#include <vector>
#include <algorithm> // for std::max

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize with the first element to handle cases like single-element arrays
        int currentSum = nums[0];
        int maxSum = nums[0];
        
        // Iterate starting from the second element
        for (int i = 1; i < nums.size(); i++) {
            // Decision: Should we start a new subarray at nums[i], 
            // or extend the previous subarray?
            // If (currentSum + nums[i]) < nums[i], it means the previous history 
            // is negative/dragging us down, so we discard it and start fresh.
            currentSum = max(nums[i], currentSum + nums[i]);
            
            // Update the global maximum found so far
            maxSum = max(maxSum, currentSum);
        }
        
        return maxSum;
    }
};