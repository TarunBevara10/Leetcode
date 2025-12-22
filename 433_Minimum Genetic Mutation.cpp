class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // 1. Store bank in a HashSet for O(1) access
        unordered_set<string> validGenes(bank.begin(), bank.end());
        
        // Edge Case: If the target is not in the bank, it's impossible
        if (validGenes.find(endGene) == validGenes.end()) return -1;
        
        // 2. Initialize Queue for BFS: {CurrentGene, Steps}
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        
        // gene characters
        char choices[] = {'A', 'C', 'G', 'T'};
        
        while (!q.empty()) {
            string current = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            // If we reached the target
            if (current == endGene) return steps;
            
            // 3. Generate all possible mutations
            // Iterate through every character in the string (length is always 8)
            for (int i = 0; i < current.length(); i++) {
                char originalChar = current[i];
                
                // Try changing it to A, C, G, T
                for (char c : choices) {
                    if (c == originalChar) continue; // Skip if same
                    
                    current[i] = c; // Mutate
                    
                    // If mutation is in the bank, it's a valid next step
                    if (validGenes.count(current)) {
                        validGenes.erase(current); // Mark as visited by removing from set
                        q.push({current, steps + 1});
                    }
                }
                
                // Backtrack: Restore the original character to try the next index
                current[i] = originalChar;
            }
        }
        
        return -1;
    }
};