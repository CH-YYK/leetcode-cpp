#include <vector>
#include <utility>
#include <queue>

using namespace std;
double profit(double pass, double total) {
  return (pass + 1) / (total + 1) - pass / total;
}

/*Greedy + heap -> give student to the class with lowest pass ratio every time*/
class Solution {
public:
  double maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
    int n = classes.size();
    priority_queue<pair<double, pair<int, int>>> q;
    double total = 0;

    for(auto& c : classes) {
      total += (double)c[0] / c[1];
      q.push({profit(c[0], c[1]), {c[0], c[1]}});
    }

    while(extraStudents-- > 0) {
      auto [p, c] = q.top();
      q.pop();
      total += p;
      q.push({profit(c.first + 1, c.second + 1), {c.first+1, c.second + 1}});
    }
    return total / n;
  }
};
