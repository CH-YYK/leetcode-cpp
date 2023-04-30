// Hello, this is a CPP leetcode snippet.

#include <algorithm>
#include <climits>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/*
ios_base::sync_with_stdio(0);
cin.tie(NULL);
*/

class Solution {
 public:
  int strStr(string haystack, string needle) {
    // if needle is a substring of haystack
    return match(haystack, needle);
  }

 private:
  vector<int> compute(string& s) {
    // lps[i]: index to the end of longest prefix that prefix = suffix
    //  in s[:i+1] (including s[i])
    //
    // lps[i] =
    vector<int> lps(s.size(), -1);
    int j = -1;
    for (int i = 1; i < s.size(); ++i) {
      // s(,j) and s(,i-1)
      // find a j to have s(,j + 1) and s(,i) match
      while (j > -1 && s[j + 1] != s[i]) j = lps[j];
      if (s[i] == s[j + 1]) j++;
      lps[i] = j;
    }
    return lps;
  }

  int match(string& s, string& p) {
    vector<int> lps = compute(p);
    int j = -1;
    for (int i = 0; i < s.size(); ++i) {
      while (j > -1 && p[j + 1] != s[i]) j = lps[j];
      if (s[i] == p[j + 1]) j++;
      if (j == p.size() - 1) return i - p.size() + 1;
    }
    return -1;
  }
};