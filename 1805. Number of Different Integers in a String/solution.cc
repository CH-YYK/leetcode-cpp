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
    int numDifferentIntegers(string word) {
  		// 
  		word += 'a';
  		string num;
  		unordered_set<string> s;
  		for(char c : word) {
  			if(isdigit(c)) {
  				if(num.size() == 1 && num.back() == '0')
  					num.pop_back();
  				num += c;
  			} else {
  				if(!num.empty())
  					s.insert(num);
  				num.clear();
  			}
  		}
  		return s.size();
    }
};

int main() {
    
}
