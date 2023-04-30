#include <vector>
#include <stack>
#include <utility>
using namespace std;

/* A value in arr, arr[i], can only be removed by the next greater value, arr[j], and generate cost of arr[i] * arr[j]
 * Use a stack to save arr[i] and let comming arr[j] that's greater than arr[i] pop it from stack and add cost arr[i] * arr[j]
 */
class Solution {
public:
  int mctFromLeafValues(vector<int> &arr) {
    int res = 0, n = arr.size();
    stack<int> stk({INT_MAX});
    for(int num : arr) {
      while(stk.top() <= num) {
        int mid = stk.top();
        stk.pop();
        res += mid * min(stk.top(), num);
      }
      stk.push(num);
    }

    while(stk.size() > 1) {
      int a = stk.top();
      stk.pop();
      res += a * stk.top();
    }
    return res;
  }
};
