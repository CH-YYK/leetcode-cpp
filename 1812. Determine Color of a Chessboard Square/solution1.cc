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
    bool squareIsWhite(string coordinates) {
  		// a1 is black
  		int posx = coordinates[0] - 'a';
  		int posy = coordinates[1] - '0';
  		if((posx + posy) & 1) return true;
  		else return false;
    }
};