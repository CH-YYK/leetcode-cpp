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


class Solution2 {
    // two-end BFS using set
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict(wordList.begin(), wordList.end());

        if(!wordDict.count(endWord)) return 0;

        unordered_set<string> q1({beginWord});
        unordered_set<string> q2({endWord});

        int step = 0;
        while(!q1.empty() && !q2.empty()) {
            step++;
            if(q1.size() > q2.size()) 
                swap(q1, q2);
            unordered_set<string> q;
            for(string w : q1) {
                for(int i = 0; i < w.size(); i++) {
                    char ch = w[i];
                    for(int j = 'a'; j <= 'z'; j++) {
                        w[i] = j;
                        if(q2.count(w)) return step + 1;
                        if(!wordDict.count(w)) continue;

                        wordDict.erase(w);
                        q.insert(w);
                    }
                    w[i] = ch;
                }
            }
            swap(q, q1);
        }
        return 0;
    }
};

class Solution3 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict(wordList.begin(), wordList.end());

        if(!wordDict.count(endWord)) return 0;

        unordered_set<string> q1({beginWord});
        unordered_set<string> q2({endWord});

        int step = 0;
        while(!q1.empty() && !q2.empty()) {
            step++;
            if(q1.size() > q2.size()) 
                swap(q1, q2);

            // required: since q1 and q2 are sets that doesn't allow indexing
            unordered_set<string> q;
            for(string w : q1) {
                for(int i = 0; i < w.size(); i++) {
                    char ch = w[i];
                    for(int j = 'a'; j <= 'z'; j++) {
                        w[i] = j;
                        if(q2.count(w)) return step + 1;
                        if(!wordDict.count(w)) continue;

                        wordDict.erase(w);
                        q.insert(w);
                    }
                    w[i] = ch;
                }
            }
            swap(q, q1);
        }
        return 0;
    }
}