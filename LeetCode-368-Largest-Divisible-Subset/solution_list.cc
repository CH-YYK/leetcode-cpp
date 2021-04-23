#include <vector>
#include <algorithm>
#include <list>
using namespace std;

// 48ms 71%
struct Node {
  int val;
  int cnt;
  Node *prev;
  Node(int val) : val(val), cnt(1), prev(nullptr) {}
  ~Node() { delete prev; }
};

class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    const int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<Node *> listnums;
    for (int num : nums)
      listnums.emplace_back(new Node(num));

    int idx = 0, maxcnt = 1;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] % nums[j] == 0)
          if (listnums[j]->cnt + 1 > listnums[i]->cnt) {
            listnums[i]->cnt = listnums[j]->cnt + 1;
            listnums[i]->prev = listnums[j];
          }
      }
      if (listnums[i]->cnt > maxcnt)
        maxcnt = listnums[i]->cnt, idx = i;
    }

    vector<int> ans;
    Node *res = listnums[idx];
    while (res) {
      ans.push_back(res->val);
      res = res->prev;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
