#include <vector>
using namespace std;

class Solution {
public:
  int findTheWinner(int n, int k) {
    vector<int> people(n, 1);
    int m = n, kt = k;
    int i = 0;
    while (n > 0) {
      i %= m;
      if (people[i] == 0)
        i++;
      else if (kt > 1) {
        kt--;
        i++;
      } else {
        people[i] = 0;
        n--;
        kt = k;
      }
    }
    return i % m + 1;
  }
};
