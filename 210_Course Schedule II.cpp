class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        // 1. Build Graph and Indegree Array
        for (auto& edge : prerequisites) {
            int course = edge[0];
            int prereq = edge[1];
            
            // Edge direction: prereq -> course
            adj[prereq].push_back(course);
            indegree[course]++;
        }
        
        // 2. Add all courses with 0 prerequisites to the queue
        // Using vector as a queue to avoid including <queue> if strictly minimizing headers,
        // but standard BFS uses a queue.
        vector<int> q; 
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push_back(i);
            }
        }
        
        vector<int> result;
        int head = 0; // Head pointer for our vector-based queue simulation
        
        // 3. Process the queue
        while(head < q.size()){
            int current = q[head++];
            result.push_back(current);
            
            for(int neighbor : adj[current]){
                indegree[neighbor]--;
                if(indegree[neighbor] == 0){
                    q.push_back(neighbor);
                }
            }
        }
        
        // 4. Check for cycles
        if (result.size() == numCourses) {
            return result;
        } else {
            return {};
        }
    }
};