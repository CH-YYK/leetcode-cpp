// Hello, this is a CPP leetcode snippet.

#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/*
ios_base::sync_with_stdio(0);
cin.tie(NULL);
*/

class Solution {
 public:
  vector<int> countPoints(vector<vector<int>>& points,
                          vector<vector<int>>& queries) {
    vector<int> answers(queries.size(), 0);
    int i = 0;
    for (auto& q : queries) {
      for (auto& p : points) {
        if ((q[0]-p[0])*(q[0]-p[0])+(q[1]-p[1])*(q[1]-p[1]) <= q[2]*q[2]) 
        	answers[i]++;
      }
      i++;
    }
    return answers;
  }
};