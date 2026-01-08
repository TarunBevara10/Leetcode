#include <vector>
#include <numeric> // For accumulate if needed, though we do it manually below
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        
        // Variables for standard Max Subarray (Kadane's)
        int currMax = 0;
        int globalMax = nums[0];
        
        // Variables for Min Subarray (Inverse Kadane's)
        int currMin = 0;
        int globalMin = nums[0];
        
        for (int x : nums) {
            // 1. Calculate Total Sum
            totalSum += x;
            
            // 2. Standard Kadane's (Find Max)
            currMax = max(x, currMax + x);
            globalMax = max(globalMax, currMax);
            
            // 3. Inverse Kadane's (Find Min)
            currMin = min(x, currMin + x);
            globalMin = min(globalMin, currMin);
        }
        
        // Edge Case: If all numbers are negative, globalMax will be negative.
        // In this case, the circular sum logic (totalSum - globalMin) would return 0,
        // which is incorrect because we need a non-empty subarray.
        if (globalMax < 0) {
            return globalMax;
        }
        
        // Otherwise, return the best of the two cases
        return max(globalMax, totalSum - globalMin);
    }
};