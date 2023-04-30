#include <memory>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> indexPairs(string text, vector<string> &words) {
    vector<vector<int>> nexts(words.size());
    for(string& w : words) {
      vector<int> tmp(w.length(), -1);
      build(w, tmp);
      nexts.emplace_back(move(tmp));
    }

    vector<vector<int>> res;
    for(string& w : words) {
      vector<int> tmp = search(text, w);
      for(int i : tmp)
        res.push_back({i, (int)w.length() + i - 1});
    }
    sort(res.begin(), res.end());
    return res;
  }
private:
  vector<int> search(string& s, string& p) {
    vector<int> ret;
    int j = -1;
    vector<int> nexts(p.size(), -1);
    build(p, nexts);
    for(int i = 0; i < s.length(); ++i) {  // start comparing [0] to s[0]
      while(j > -1 && p[j+1] != s[i])
        j = nexts[j];
      if(p[j+1] == s[i])
        ++j;
      if(j+1 == p.length())  // finish comparing the final character
        ret.push_back(i - j);
    }
    return ret;
  }

  void build(string& p, vector<int>& nexts) {
    int j = -1;  // initial state to match p[0]
    for(int i = 1; i < p.size(); ++i) {  // start comparing p[1] to p[0]
      while(j > -1 && p[j+1] != p[i])
        j = nexts[j];
      if(p[i] == p[j+1]) j++;
      nexts[i] = j;
    }
  }
};
