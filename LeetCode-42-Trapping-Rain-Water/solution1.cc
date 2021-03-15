#include <vector>
#include <stack>>

using namespace std;

/* Monotone stack find next higher as bar
 */
class Solution {
public:
  int trap(vector<int> &height) {
    int n = height.size();
    if (n < 3)
      return 0;
    vector<int> pos(n, -1);
    stack<int> s; // maxheap by default
    int tmp = -1;
    for (int i = n - 1; i >= 0; --i) {
      while (!s.empty() && height[s.top()] < height[i]) {
        tmp = s.top();
        s.pop();
      }
      if (!s.empty())
        pos[i] = s.top();
      else
        pos[i] = tmp;
      s.push(i);
    }

    int volume = 0;
    int res = 0;
    int i = 0, j;
    while (i < n - 1) {
      j = i + 1;
      while (j < pos[i])
        volume += height[j++];
      res += min(height[i], height[j]) * (j - i - 1) - volume;
      volume = 0;
      i = j;
    }
    return res;
  }
};
