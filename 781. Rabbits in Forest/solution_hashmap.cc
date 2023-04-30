#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int numRabbits(vector<int> &answers) {
    unordered_map<int, int> counts;
    int res = 0;
    for(int num : answers)
      counts[num+1]++;
    for(auto p : counts) {
      if(p.second < p.first) res += p.first;
      // + p.first-1 is an offset make sure the resulted float convert to its upper bound
      else res += (p.second + p.first - 1) / p.first * p.first;
    }
    return res;
  }
};
