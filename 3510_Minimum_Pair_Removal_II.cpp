#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        // DLL Simulation
        vector<long long> val(n);
        vector<int> next(n);
        vector<int> prev(n);
        // Track removed nodes to prevent "ghost" merges
        vector<bool> removed(n, false);

        // Min-heap: {sum, left_index}
        // greater<> ensures we pick smallest sum, then smallest index (leftmost)
        typedef pair<long long, int> P;
        priority_queue<P, vector<P>, greater<P>> pq;

        int inversion_count = 0;

        // Initialization
        for (int i = 0; i < n; ++i) {
            val[i] = nums[i];
            next[i] = (i == n - 1) ? -1 : i + 1;
            prev[i] = (i == 0) ? -1 : i - 1;

            if (i < n - 1) {
                if (nums[i] > nums[i+1]) {
                    inversion_count++;
                }
                pq.push({(long long)nums[i] + nums[i+1], i});
            }
        }

        if (inversion_count == 0) return 0;

        int ops = 0;

        while (!pq.empty()) {
            auto [sum, i] = pq.top();
            pq.pop();

            // 1. Check if 'i' is already removed
            if (removed[i]) continue;

            // 2. Check if the pair is stale
            // We need to verify 'i' is still connected to the neighbor we summed with
            // and the values match.
            int j = next[i];
            if (j == -1 || val[i] + val[j] != sum) {
                continue;
            }

            // --- Perform Merge (i, j) -> i ---

            // Step 1: Remove Inversions involving i or j
            // (prev[i], i)
            if (prev[i] != -1 && val[prev[i]] > val[i]) inversion_count--;
            // (i, j)
            if (val[i] > val[j]) inversion_count--;
            // (j, next[j])
            if (next[j] != -1 && val[j] > val[next[j]]) inversion_count--;

            // Step 2: Update Values and Pointers
            val[i] += val[j];
            removed[j] = true; // Mark j as removed

            int k = next[j];
            next[i] = k;
            if (k != -1) {
                prev[k] = i;
            }
            // Note: We do not strictly need to update prev[j] or next[j] as j is marked removed.

            // Step 3: Add New Inversions
            // (prev[i], i)
            if (prev[i] != -1 && val[prev[i]] > val[i]) inversion_count++;
            // (i, k) - k is the new next[i]
            if (next[i] != -1 && val[i] > val[next[i]]) inversion_count++;

            ops++;

            if (inversion_count == 0) return ops;

            // Step 4: Push New Pairs
            // Left neighbor: (prev[i], i)
            if (prev[i] != -1) {
                pq.push({val[prev[i]] + val[i], prev[i]});
            }
            // Right neighbor: (i, next[i])
            if (next[i] != -1) {
                pq.push({val[i] + val[next[i]], i});
            }
        }

        return ops;
    }
};
