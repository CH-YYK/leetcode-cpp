#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> wordDict(wordList.begin(), wordList.end());

    if(wordDict.count(endWord)) wordDict.erase(endWord);
    else return 0;

    unordered_set<string> set1({beginWord}), set2({endWord}), tmp;

    int step1 = 1, step2 = 1;
    unordered_set<string>* curr = &set1, *next = &set2;

    while(!curr->empty()) {
      for(auto it = curr->begin(); it != curr->end(); ++it) {
        string w = *it;
        for(int j = 0; j < w.length(); ++j) {
          char c = w[j];
          for(char k = 'a'; k <= 'z'; ++k) {
            if(k != c) w[j] = k;
            if(next->count(w)) return step1 + step2;
            if(!wordDict.count(w)) continue;
            wordDict.erase(w);  // erase the word if word has been added to sets
            tmp.insert(w);
          }
          w[j] = c;
        }
      }
      step1++;
      *curr = move(tmp);  // use move to avoid extra copy and clearing tmp
      swap(curr, next), swap(step1, step2);
    }

    return 0;
  }
};
