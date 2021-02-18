#include <vector>

using namespace std;

/* Use list to allow O(1) insersion and deletion
 * Order in descending height and smaller K to match "greedy" preassumption.
 */
bool taller_person(vector<int>& lhs, vector<int>& rhs) {
  if(lhs[0] > rhs[0]) return true;
  else if(lhs[0] == rhs[0]) return lhs[1] < rhs[1];
  return false;
}

class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    if(people.empty()) return {};

    sort(people.begin(), people.end(), taller_person);
    list<vector<int>> queue_;
    vector<vector<int>> res;

    int i = 0;
    for(auto& p : people) {
      if(i > p[1]) {
        auto it = queue_.begin();
        advance(it, p[1]);
        queue_.insert(it, p);
      } else
        queue_.push_back(p);
      ++i;
    }

    for(auto& p : queue_)
      res.emplace_back(p);
    return res;
  }
};
