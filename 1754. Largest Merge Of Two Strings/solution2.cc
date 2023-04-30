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
  string largestMerge(string word1, string word2) {
    // take larger one of word1 and word2
    // O(M^2 + N^2)
    // without std::string::compare
    string merge;
    int i = 0, j = 0;
    while (i < word1.size() || j < word2.size()) {
      if (i == word1.size()) {
        merge += word2[j++];
        continue;
      }
      if (j == word2.size()) {
        merge += word1[i++];
        continue;
      }
      // compare word1[i:] and word2[j:]
      int ni = i, nj = j;
      while (ni < word1.size() && nj < word2.size() && word1[ni] == word2[nj])
        ni++, nj++;
      if (ni == word1.size() || word1[ni] < word2[nj])
        merge += word2[j++];
      else
        merge += word1[i++];
    }
    return merge;
  }
};