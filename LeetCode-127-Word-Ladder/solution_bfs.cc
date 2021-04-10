#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> wordDict(wordList.begin(), wordList.end());

    if(wordDict.count(endWord)) wordDict.erase(endWord);
    else return 0;

    queue<string> q;
    q.push(beginWord);
    int step = 1;
    while (!q.empty()) {
      int size_ = q.size();
      for (int i = 0; i < size_; ++i) {
        string w = q.front();
        q.pop();
        for (int j = 0; j < w.size(); ++j) {
          char c = w[j];
          for (int k = 0; k < 26; ++k) {
            if (c - 'a' != k)
              w[j] = 'a' + k;
            if (w == endWord)
              return step + 1;
            if (!wordDict.count(w))
              continue;
            wordDict.erase(w);
            q.push(w);
          }
          w[j] = c;
        }
      }
      step++;
    }
    return 0;
  }
};
