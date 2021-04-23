#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.empty()) // edge case handler
      return 0;
    return search(haystack, needle);
  }

private:
  int search(string &s, string &p) {
    int j = -1;
    vector<int> nexts(p.length(), -1);
    build(p, nexts);
    for (int i = 0; i < s.length(); ++i) {
      while (j > -1 && p[j + 1] != s[i])
        j = nexts[j];
      if (s[i] == p[j + 1])
        j++;
      if (j + 1 == p.length())
        return i - p.length() + 1;
    }
    return -1;
  }

  void build(string &p, vector<int> &prefix) {
    int j = -1;
    for (int i = 1; i < p.length(); ++i) {
      while (j > -1 && p[j + 1] != p[i])
        j = prefix[j];
      if (p[j + 1] == p[i])
        j++;
      prefix[i] = j;
    }
  }
};

