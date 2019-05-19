#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // convert wordDict to hashmap
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        if(!wordDict.count(endWord)) return 0;

        // hashmap for steps
        unordered_map<string, int> steps = {{beginWord, 1}};

        // build queue
        queue<string> Queue({beginWord});
        int step = 0;
        int l = beginWord.size();

        while(!Queue.empty()){
            // pop value from front
            string currWord = Queue.front();
            Queue.pop();

            if(steps.count(currWord)) step = steps[currWord];

            for(int i = 0; i < l; i++) {
                char ch = currWord[i];
                for(char j = 'a'; j <= 'z'; j++) {
                    currWord[i] = j;
                    if(currWord == endWord) return step+1;
                    if(!wordDict.count(currWord)) continue;

                    steps[currWord] = step+1;
                    wordDict.erase(currWord); // remove: re-reach to current word result in longer path
                    Queue.push(currWord);
                }
                currWord[i] = ch;
            }
        }
        return 0;
    }
};