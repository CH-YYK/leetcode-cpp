#include <vector>
using namespace std;

class Solution {
public:
  int getXORSum(vector<int> &arr1, vector<int> &arr2) {
    int m = arr1.size(), n = arr2.size();
    int res = 0;
    int l = 0, r = 0;
    for(int i = 31; i >= 0; --i) {
      l = 0, r = 0;
      for(int num : arr1)
        if(num & 1 << i) l++;
      for(int num : arr2)
        if(num & 1 << i) r++;
      // num1 : l * r, num0 m*n - l*r
      int num1 = l * r;
      if(num1 & 1) res += 1 << i;
    }
    return res;
  }
};
