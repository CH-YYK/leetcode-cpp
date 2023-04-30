#include <vector>
#include <algorithm>
using namespace std;

/*
 * speed : x
 * hours : y
 * if(y <= h): (x is a possible) r = x
 * else l = x + 1
 */
class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int l = 1, r = *max_element(piles.begin(), piles.end());
    while(l < r) {
      int x = l + (r - l) / 2;
      int y = 0;
      for(int pile : piles)
        y += (pile + x - 1) / x;
      if(y <= h) r = x;
      else l = x + 1;
    }
    return l;
  }
};
