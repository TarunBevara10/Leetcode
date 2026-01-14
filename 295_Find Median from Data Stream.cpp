#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
private:
    // Max-heap to store the smaller half of the numbers
    priority_queue<int> smallHalf; 
    
    // Min-heap to store the larger half of the numbers
    // We use the standard vector container and 'greater' comparator to reverse the order
    priority_queue<int, vector<int>, greater<int>> largeHalf;

public:
    MedianFinder() {
        // No explicit initialization needed for std::priority_queue
    }
    
    void addNum(int num) {
        // Step 1: Add to smallHalf first
        smallHalf.push(num);
        
        // Step 2: Maintain Value Order
        // The largest element in smallHalf might actually belong to largeHalf.
        // Move the top of smallHalf to largeHalf to correct this.
        largeHalf.push(smallHalf.top());
        smallHalf.pop();
        
        // Step 3: Maintain Size Balance
        // We want smallHalf to be size N or N+1, and largeHalf to be size N.
        // If largeHalf has more elements, move the smallest back to smallHalf.
        if (largeHalf.size() > smallHalf.size()) {
            smallHalf.push(largeHalf.top());
            largeHalf.pop();
        }
    }
    
    double findMedian() {
        // If smallHalf has more elements (odd total), the median is its top
        if (smallHalf.size() > largeHalf.size()) {
            return (double)smallHalf.top();
        }
        
        // If sizes are equal (even total), the median is the average of the two tops
        return (smallHalf.top() + largeHalf.top()) / 2.0;
    }
};