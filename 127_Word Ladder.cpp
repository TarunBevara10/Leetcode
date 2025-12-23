#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 1. Place words in a set for O(1) lookups
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        // If endWord is not in the dictionary, a path is impossible
        if (dict.find(endWord) == dict.end()) {
            return 0;
        }
        
        // 2. Initialize BFS Queue
        queue<string> q;
        q.push(beginWord);
        
        // 3. Track depth (sequence length). Starts at 1 (counting beginWord)
        int depth = 1;
        
        while (!q.empty()) {
            int levelSize = q.size();
            
            // Process all words at the current level
            while (levelSize--) {
                string currentWord = q.front();
                q.pop();
                
                // Try changing every character of the current word
                for (int i = 0; i < currentWord.length(); ++i) {
                    char originalChar = currentWord[i];
                    
                    // Try all 26 lowercase letters
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == originalChar) continue;
                        
                        currentWord[i] = c;
                        
                        // If we found the target
                        if (currentWord == endWord) {
                            return depth + 1;
                        }
                        
                        // If the transformed word is in the dict, it's a valid neighbor
                        if (dict.find(currentWord) != dict.end()) {
                            q.push(currentWord);
                            dict.erase(currentWord); // Mark as visited by removing
                        }
                    }
                    // Restore the word for the next position iteration
                    currentWord[i] = originalChar;
                }
            }
            // Increment depth after finishing the whole level
            depth++;
        }
        
        return 0; // No path found
    }
};