#include <utility>
#include <vector>
#include <queue>

using namespace std;

double profit(double pass, double total) {
  return (pass + 1) / (total + 1) - pass / total;
}
struct pair_cmp {
  bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
    double first =  profit(lhs.first, lhs.second);
    double second = profit(rhs.first, rhs.second);
    return first < second;
  }
};

/*Greedy + heap -> find a class with highest margin pass ratio with 1 student added
 * double is precise enough to literally get the result
 */
class Solution {
public:
  double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    // pq, <greater> cmp make a greater one placed backwards
    priority_queue<pair<int, int>, vector<pair<int, int>>, pair_cmp> q;
    int n = classes.size();

    for(auto& c : classes) 
      q.push({c[0], c[1]});

    while(extraStudents-- > 0) {
      auto p = q.top();
      q.pop();
      q.push({p.first+1, p.second+1});
    }

    // compute average
    double total = 0;
    while(!q.empty()) {
      auto p = q.top();
      q.pop();
      total += (double)p.first / p.second;
    }
    return total / n;
  }
};
