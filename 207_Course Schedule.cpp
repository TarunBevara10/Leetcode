class Solution {
public:
    // Helper function to detect cycle using DFS
    // Returns true if a cycle is found, false otherwise
    bool hasCycle(int course, vector<vector<int>>& adj, vector<int>& state) {
        // If node is currently being visited in the recursion stack, we found a cycle
        if (state[course] == 1) return true;
        
        // If node is already completely processed, it's safe (no cycle here)
        if (state[course] == 2) return false;

        // Mark current node as 'Visiting'
        state[course] = 1;

        // Traverse all neighbors (courses dependent on this one)
        for (int neighbor : adj[course]) {
            if (hasCycle(neighbor, adj, state)) {
                return true;
            }
        }

        // Mark current node as 'Visited' (Processed)
        state[course] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 1. Build Adjacency List
        // We use a vector of vectors to represent the graph
        vector<vector<int>> adj(numCourses);
        
        // prerequisites[i] = [a, b] means you must take b before a.
        // So the edge is: b -> a
        for (int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i][0];
            int prereq = prerequisites[i][1];
            adj[prereq].push_back(course);
        }

        // 2. Initialize State Array
        // 0 = Unvisited, 1 = Visiting, 2 = Visited
        vector<int> state(numCourses, 0);

        // 3. Iterate through every course
        // We need to loop because the graph might be disconnected (forest)
        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (hasCycle(i, adj, state)) {
                    return false; // Cycle detected, cannot finish
                }
            }
        }

        return true;
    }
};