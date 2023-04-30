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
    int maximumScore(int a, int b, int c) {
  		int first, second, third;
  		// sorting to get first > second > third
  		vector<int> inputs = {a, b, c};
  		sort(inputs.begin(), inputs.end());
  		first = inputs[2];
  		second = inputs[1];
  		third = inputs[0];

  		if(second + third <= first)
  			return second + third;
  		else 
  			return (first + second + third) / 2;
    }
};