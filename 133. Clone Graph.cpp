/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

#include <unordered_map>

class Solution {
public:
    // Hash map to save the visited nodes: 
    // Key = Original Node*, Value = Cloned Node*
    std::unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        // 1. Handle edge case for empty graph
        if (node == nullptr) {
            return nullptr;
        }

        // 2. If we have already cloned this node, return the clone from the map
        if (visited.count(node)) {
            return visited[node];
        }

        // 3. Create the new node (The Clone)
        Node* clone = new Node(node->val);
        
        // 4. Save to map IMMEDIATELY to prevent cycles/infinite loops
        visited[node] = clone;

        // 5. Iterate through neighbors and clone them recursively
        for (Node* neighbor : node->neighbors) {
            // Recursive call ensures we get the clone of the neighbor
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};