#include <string>
using namespace std;

class Solution {
public:
  bool squareIsWhite(string coordinates) {
    return (coordinates[0] - 'a' + 1 + coordinates[1]) % 2 == 1;
  }
};
