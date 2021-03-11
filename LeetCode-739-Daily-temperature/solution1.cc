#include <stack>
#include <pair>

using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& T) {
    stack<pair<int, int>> s;  // monotune stack, keep ascending ordered values
    int n = T.size();

    vector<int> res(n, 0);

    for(int i = n-1; i >= 0; --i) {
      if(s.empty()) s.push({T[i], i});
      else {
        while(!s.empty() && T[i] >= s.top().first)
          s.pop();
        if(!s.empty())
          res[i] = s.top().second - i;
        s.push({T[i], i});
      }
    }
    return res;
  }
};
