using namespace std;

class Solution {
public:
  bool judgeSquareSum(int c) {
    long l = 0, r = 0;
    long d = c;
    while(r * r < c) ++r;

    while(l <= r) {
      if(l * l > c - r * r) --r;
      else if(l * l  == c - r * r) return true;
      else ++l;
    }
    return false;
  }
};
