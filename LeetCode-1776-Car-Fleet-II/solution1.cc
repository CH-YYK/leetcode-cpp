/* nums of cars of size n, along with spds and pos
 * Suppose we are considering 3 cars in a sequence {a, b, c, d}
 *   - chasing time between (a, b) can be computed by (p_b - p_a) / (s_b - s_a) if(s_b >= s_a)
 *   - chasing time for (a, b) would be transformed to (a, c) if a catches b later than b catches c 
 */

class Solution {
public:
  vector<double> getCollisionTimes(vector<vector<int>>& A) {
    int n = A.size();

    vector<double> res(n, -1);
    stack<int> s;  // index of cars past to current

    for(int i = n-1; i >= 0; --i) {
      int currpos = A[i][0], currspd = A[i][1];
      while(!s.empty()) {
        int prev = s.top(), prevpos = A[prev][0], prevspd = A[prev][1];
        /* Infinite chasing time || longer chasing time than the last one -> pop the stack and chase next
         * res[prev] > 0 -> last car can chase the one next
         */
        if(currspd <= prevspd ||(1.0 * (prevpos - currpos) / (currspd - prevspd) > res[prev] && res[prev] > 0))
          s.pop();
        else {
          res[i] = 1.0 * (prevpos - currpos) / (currspd - prevspd);
          break;
        }
      }
      s.push(i);
    }
    return res;
  }
};
