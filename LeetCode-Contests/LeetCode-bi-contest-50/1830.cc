#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int makeStringSorted(string s) {
    return mergeSort(s, 0, s.size() - 1);
  }
private:
  int mergeSort(string &s, int lo, int hi) {
    if (lo >= hi)
      return 0;
    int k = (lo + hi) / 2;
    int res = 0;
    res += mergeSort(s, lo, k);
    res += mergeSort(s, k + 1, hi);
    res += merge(s, lo, k, hi);
    return res;
  }
  int merge(string &s, int lo, int mid, int hi){
    
  }
};
