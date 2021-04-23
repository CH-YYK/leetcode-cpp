#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<int> countPoints(vector<vector<int>> &points,
                          vector<vector<int>> &queries) {
    vector<int> answer(queries.size(), 0);
    int index = 0;
    for (auto &q : queries) {
      for (auto &p : points) {
        if (distance({q[0], q[1]}, p) <= q[2] * q[2])
          answer[index]++;
      }
      index++;
    }
    return answer;
  }

private:
  int distance(vector<int> p1, vector<int> p2) {
    int dis = 0;
    for (int i = 0; i < 2; ++i)
      dis += (p1[i] - p2[i]) * (p1[i] - p2[i]);
    return dis;
  }
};
