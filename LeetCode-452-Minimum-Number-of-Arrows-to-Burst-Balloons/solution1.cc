#include <vector>
#include <algorithm>

using namespace std;

bool less_vector(const vector<int>& lhs,  const vector<int>& rhs) { 
  // rrank by the left side x_start.
  // make the comparator "strictly weak ordering"
  return lhs[0] < rhs[0];
}

class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    if(points.empty()) return 0;

    sort(points.begin(), points.end(), less_vector);

    int res = 1;
    int right = points[0][1];

    for(int i = 1; i < points.size(); ++i) {
      if(points[i][0] <= right)
        right = min(points[i][1], right);
      else {
        right = points[i][1];
        ++res;
      }
    }
    return res;
  }
};
