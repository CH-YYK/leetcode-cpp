#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

/* Find all palindrome prefix/suffix put the reversed rest in hashmap
 * TC: O(k^2*n)
 */
class Solution {
public:
  vector<vector<int>> palindromePairs(vector<string> &words) {
    int n = words.size();
    for (const string &w : words) {
      wordsRev.push_back(w);
      reverse(begin(wordsRev.back()), end(wordsRev.back()));
    }
    // put reversed words in dictionary
    for (int i = 0; i < n; ++i)
      indices.emplace(wordsRev[i], i);

    // for each word in words, after extracting palindrome prefix/suffix,
    // check whether the rest of substring in dictionary
    vector<vector<int>> ret;
    for (int i = 0; i < n; ++i){
      int m = words[i].size();
      if(!m) continue;
      string wordView(words[i]);
      for(int j = 0; j <= m; ++j) {
        if(isPalindrome(wordView, j, m-1)) { // palindrome suffix
          int right_id = findWord(wordView, 0, j-1);
          if(right_id != -1 && right_id != i)
            ret.push_back({i, right_id});
        }

        if(j > 0 && isPalindrome(wordView, 0, j-1)) { // palindrome prefix
          int left_id = findWord(wordView, j, m-1);
          if(left_id != -1 && left_id != i)
            ret.push_back({left_id, i});
        }
      }
    }
    return ret;
  }
private:
  vector<string> wordsRev;
  unordered_map<string, int> indices;

  int findWord(const string& s, int left, int right) {
    if(indices.count(s.substr(left, right - left + 1)))
      return indices[s.substr(left, right - left + 1)];
    else return -1;
  }
  bool isPalindrome(const string& s, int i, int j) {
    while(i < j){
      if(s[i++] != s[j--]) return false;
    }
    return true;
  }
};
 
