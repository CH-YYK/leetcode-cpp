#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;
/* base2: [0, 1] -> [0, 1, 2]: 2^0 + 2^1 = 2 ^ 0 - 2 ^ 1 + 2 ^ 2
 *      => (-2) ^ 0 + (-2) ^ 1 + (-2) ^ 2
 */
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
