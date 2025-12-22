#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // Adjacency list: Node -> Vector of {Neighbor, Weight}
    unordered_map<string, vector<pair<string, double>>> adj;

    // Depth First Search to find path from 'current' to 'target'
    double dfs(string current, string target, unordered_set<string>& visited) {
        // Base case: If we reached the target, the ratio of target/target is 1.0
        // The accumulation happens as the recursion unwinds.
        if (current == target) {
            return 1.0;
        }
        
        visited.insert(current);

        // Explore neighbors
        for (auto& edge : adj[current]) {
            string neighbor = edge.first;
            double weight = edge.second;

            if (visited.find(neighbor) == visited.end()) {
                double result = dfs(neighbor, target, visited);
                // If a valid path was found (result != -1.0)
                if (result != -1.0) {
                    return weight * result;
                }
            }
        }

        // Backtrack: No path found from this node
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        adj.clear();
        
        // 1. Build the Graph
        for (int i = 0; i < equations.size(); ++i) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            // Add forward edge: u / v = val
            adj[u].push_back({v, val});
            // Add backward edge: v / u = 1 / val
            adj[v].push_back({u, 1.0 / val});
        }

        vector<double> results;
        
        // 2. Process Queries
        for (auto& q : queries) {
            string start = q[0];
            string end = q[1];

            // Case: Variable not in graph
            if (adj.find(start) == adj.end() || adj.find(end) == adj.end()) {
                results.push_back(-1.0);
            } 
            // Case: Start == End (and exists in graph)
            else if (start == end) {
                results.push_back(1.0);
            } 
            else {
                unordered_set<string> visited;
                results.push_back(dfs(start, end, visited));
            }
        }

        return results;
    }
};