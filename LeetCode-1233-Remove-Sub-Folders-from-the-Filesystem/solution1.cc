#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/* Sorted folder list is pre-order traversal of file system tree
 * Use the stack to save node => push s to stack if isRoot(stack.top(), s)
 * Preorder: Root->left->right
 *  case1: Root followed by left or right -> keep root only
 *  case2: Root followed by another root -> keep both
 * isRoot == isPrefix
 */

class Solution {
public:
  vector<string> removeSubfolders(vector<string> &folder) {
    if (folder.empty())
      return {};
    sort(folder.begin(), folder.end());
    vector<string> res;
    string buffer;
    for (string &s : folder) {
      if (res.empty())
        res.push_back(s);
      else if (is_prefix(res.back(), s))
        continue;
      else
        res.push_back(s);
    }
    return res;
  }

private:
  bool is_prefix(string &pref, string &folder) {
    if (pref.empty())
      return false;
    int i = 0, j = 0;
    while (i < pref.size() && j < folder.size()) {
      if (pref[i] == folder[j])
        i++, j++;
      else
        return false;
    }
    return (j < folder.size()) ? folder[j] == '/' : false;
  }
};
