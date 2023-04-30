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
    int getLucky(string s, int k) {
  		function<int(int)> transform = [](int num) {
  			int ans = 0;
  			while(num) {
  				ans += num % 10;
  				num /= 10;
  			}
  			return ans;
  		};
  		int ans = 0;
  		for(char c : s) 
            ans += transform(c - 'a' + 1);
  		while(k-- > 1) 
  			ans = transform(ans);
  		return ans;
    }
};


int main() {
    
}
