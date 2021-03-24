#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
  string baseNeg2(int N) {
    if (N == 0)
      return "0";
    vector<int> base2;
    int i = 0;
    // decode the number N to the powers at base 2
    while (N) {
      if (N % 2 == 1)
        base2.push_back(i);
      N /= 2;
      i++;
    }
    reverse(base2.begin(), base2.end());

    // convert the power series of 2 to power series of -2
    vector<int> res;
    int tmp;
    while (!base2.empty()) {
      tmp = base2.back();
      if (tmp % 2 == 0) {
        res.push_back(tmp), base2.pop_back();
      } else {
        res.push_back(tmp), base2.pop_back();
        tmp += 1;
        while (!base2.empty() && base2.back() == tmp) {
          base2.pop_back();
          tmp += 1;
        }
        base2.push_back(tmp);
      }
    }

    // convert the power series of -2 to string represented -2 base number
    string ret(tmp + 1, '0');
    for (int i : res)
      ret[tmp - i] = '1';
    return ret;
  }
};

class Solution {
public:
  bool isValidBST(TreeNode *root) {
    TreeNode *cur = root, *next = nullptr, *pre = nullptr;
    int val = -2100000000;
    while (cur != nullptr) {
      next = cur->left;
      if (next !=
          nullptr) { // 有左子树
        pre = next;
        while(pre->right != nullptr && pre->right != cur){ pre = pre->right; }
        if(pre->right == nullptr){
          pre->right = cur; cur = cur->left; continue; }

        else{ pre->right = nullptr; if(cur->val < val){ return false; }
          val = cur->val; cur = cur->right; continue; } }
      // 无左子树
      if(cur->val < val){ return false; } val = cur->val; cur = cur->right; } return true; } };
