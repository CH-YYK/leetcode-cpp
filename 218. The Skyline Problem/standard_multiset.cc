#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
    // events, x, h
    typedef vector<int> Event;
    vector<vector<int>> es;
    hs_.clear();

    for(const auto& b : buildings) {
      es.push_back({b[0], b[2]});  // for entering event, higher first (>0: entering)
      es.push_back({b[1], -b[2]}); // for departing event, lower first (<0: leaving)
    }
    // sort events by x
    sort(es.begin(), es.end(), [](const Event& e1, const Event& e2) {
      if(e1[0] == e2[0]) return e1[1] > e2[1];
      return e1[0] < e2[0];
    });

    vector<vector<int>> ans;
    for(const auto& e : es) {
      int x = e[0];
      bool entering = e[1] > 0;
      int h = abs(e[1]);
      if(entering) {
        if(h > maxHeight())
          ans.push_back({x, h});
        hs_.insert(h);
      }else {
        hs_.erase(hs_.equal_range(h).first);
        if(h > maxHeight())
          ans.push_back({x, maxHeight()});
      }
    }
    return ans;
  }
private:
  int maxHeight() const {
    if(hs_.empty()) return 0;
    else return *hs_.rbegin();
  }
  multiset<int> hs_;
};
