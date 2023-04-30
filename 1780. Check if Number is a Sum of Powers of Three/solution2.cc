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

int main() {
    
}

class Solution {
public:
  bool checkPowersOfThree(int n) {
  	// Trinary number
  	while(n) {
  		if(n % 3 == 2)
  			return false;
  		n /= 3;
  	}
  	return true;
  }
};