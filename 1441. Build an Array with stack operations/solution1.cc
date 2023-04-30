#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  vector<string> buildArray(vector<int> &target, int n) {
    int i = 0;
    vector<string> res;
    for(int j = 1; j <= n && i < target.size(); ++j) {
      if(target[i] == j) res.push_back("Push"), ++i;
      else {
        res.push_back("Push");
        res.push_back("Pop");
      }
    }
    return res;
  }
};
