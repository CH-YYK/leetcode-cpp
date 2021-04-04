#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int numRabbits(vector<int> &answers) {
    vector<int> counts(1000, 0);
    int res = 0;
    for (int num : answers)
      counts[num]++;

    for (int i = 0; i < 1000; ++i) {
      if (counts[i] == 0)
        continue;
      if (i + 1 > counts[i])
        res += (i + 1);
      else
        res += (counts[i] + i) / (i + 1) * (i + 1);
    }
    return res;
  }
};
