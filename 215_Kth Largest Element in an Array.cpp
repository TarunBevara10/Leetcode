class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Create a min-heap (smallest element is at the top)
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int num : nums) {
            minHeap.push(num);
            
            // If we have more than k elements, remove the smallest one
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        // The top of the heap is now the kth largest element
        return minHeap.top();
    }
};