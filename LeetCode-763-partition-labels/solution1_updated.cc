#include <vector>

using namespace std;

class Solution {

  // preprocess data and transform to an useful way
 public:
  vector<int> partitionLabels(string S) {
    if(S.empty()) return {};

    vector<int> res;
    unordered_set<char> set_;
    vector<int> map_(26, 0);

    for(char c : S) map_[c - 'a']++;

    int l = -1;
    char c;

    for(int r = 0 ; r < S.size(); ++r) {
      c = S[r];
      set_.insert(c);

      if(--map_[c-'a'] == 0) set_.erase(c);

      if(set_.empty()) {
        res.push_back(r - l);
        l = r;
      }
    }
    return res;
  }
};
