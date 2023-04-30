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

class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
  		// Lowest Common Ancestor
  		// [4,7]: 4,2,1 and 7,3,1 -> 5
  		// [2,3]: 2,1 and 3,1 -> 3
  		vector<int> answers;
  		for(vector<int>& query : queries) {
  			// b > a
  			int b = query[0] > query[1] ? query[0] : query[1];
  			int a = query[0] > query[1] ? query[1] : query[0];
  			int num = 0;
  			while(b != a) {
  				while(b > a) {
  					b /= 2;
  					num++;
  				}
  				while(a > b) {
  					a /= 2;
  					num++;
  				}
  			}
  			num++;
  			answers.push_back(num);
  		}
  		return answers;
    }
};