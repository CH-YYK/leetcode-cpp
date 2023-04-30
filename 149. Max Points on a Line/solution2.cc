// Hello, this is a CPP leetcode snippet.

#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <functional>
#include <climits>
#include <set>
#include <map>
#include <sstream>

using namespace std;

/*		
ios_base::sync_with_stdio(0); 
cin.tie(NULL);
*/


class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
      // start from each point (as a start point)
      // wont reuse the previous ones
      // a line is defined by starting point (enumerating each point) and a slope (a pair of points)
      // 1. enumerating each starting point
      // 2. compute the slopes and reduce them use GCD
      // 3. track the maximum amount of points on each line
      //
      // solution2 make each point a starting point and find if other points are on the line
      // solution1 are checking whether a pointj can be on one of the lines of pointi
      // solution2 would use less max space, solution1 keep all of the states
      
      const int N = points.size();
      int res = 0;
      for(int i = 0; i < N; ++i) {
        map<pair<int, int>, int> slopes;
        int _max = 1;
        for(int j = i + 1; j < N; ++j) {
          int dx = points[j][0] - points[i][0];
          int dy = points[j][1] - points[i][1];
          int _gcd = gcd(dx, dy);
          
          if(dx * dy > 0) dx = abs(dx), dy = abs(dy);
          else dx = abs(dx), dy = -abs(dy);

          pair<int,int> slope = {dx / _gcd, dy / _gcd};          
          if(slopes.count(slope)) 
            _max = max(_max, ++slopes[slope]);
          else 
            _max = max(_max, slopes[slope] = 2);
        }
        res = max(res, _max);
      }
      return res;
    }
};