#include <vector>
#include <string>
using namespace std;

/* Sort the nums 
 * * numbers with larger preceding digits comes firstly
 * * If one number,a, is prefix of another one,b, i.e b = a*10^x + y
 */
bool cmp_string(const int lhs, const int &rhs) {
  if (lhs == rhs)  // put lhs right to rhs if equal, strickly less
    return false;
  else
    return (to_string(lhs) + to_string(rhs)) >
           (to_string(rhs) + to_string(rhs));
}

class Solution {
public:
  string largestNumber(vector<int> &nums) {
    string res;
    sort(begin(nums), end(nums), cmp_string);
    for (int n : nums) {
      if (res.empty() && n == 0)
        return "0";
      else
        res += to_string(n);
    }
    return res;
  }
};
