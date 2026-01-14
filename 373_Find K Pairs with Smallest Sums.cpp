#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        int n = nums1.size();
        int m = nums2.size();
        
        // Min-heap storing {sum, {index_in_nums1, index_in_nums2}}
        // We use 'greater' for min-heap behavior
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;

        // Initialize the heap with the first pair from each "row" (nums1 element)
        // We only need to check the first k elements of nums1 because the output size is limited to k.
        for (int i = 0; i < n && i < k; ++i) {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }

        // Extract the smallest pair k times (or until heap is empty)
        while (k-- > 0 && !pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int i = top.second.first; // index in nums1
            int j = top.second.second; // index in nums2

            result.push_back({nums1[i], nums2[j]});

            // If there is a next element in nums2 for this specific nums1[i], push it
            if (j + 1 < m) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }

        return result;
    }
};