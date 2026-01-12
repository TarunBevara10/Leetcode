class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        
        // Store projects as pairs: {capital_required, profit}
        vector<pair<int, int>> projects;
        for(int i = 0; i < n; ++i) {
            projects.push_back({capital[i], profits[i]});
        }
        
        // Sort based on capital required (ascending)
        sort(projects.begin(), projects.end());
        
        // Max-Heap to store profits of 'available' projects
        priority_queue<int> maxProfitHeap;
        
        int i = 0;
        
        // We can select at most k projects
        while(k--) {
            // 1. Add all projects we can afford with current capital 'w' to the heap
            while(i < n && projects[i].first <= w) {
                maxProfitHeap.push(projects[i].second);
                i++;
            }
            
            // 2. If the heap is empty, we can't afford any more projects, so stop early
            if(maxProfitHeap.empty()) {
                break;
            }
            
            // 3. Pick the project with maximum profit
            w += maxProfitHeap.top();
            maxProfitHeap.pop();
        }
        
        return w;
    }
};