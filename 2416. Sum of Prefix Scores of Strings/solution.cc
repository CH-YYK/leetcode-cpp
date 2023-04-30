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
    vector<int> sumPrefixScores(vector<string>& words) {
  		// hashmap: prefix matching
  		// O(N*L*appr(NL))
  		// trie tree or hashmap
  		// L <= 1000 -> 1000 prefix
  		// N <= 1000 -> NL = 10^6
  		unordered_map<string, int> mp;
  		for(string& w : words) {
  			string prefix;
  			for(char c : w) {
  				prefix += c;
  				mp[prefix]++;
  			}
  		}
  		vector<int> answers(words.size(), 0);
  		for(int i = 0; i < words.size(); ++i) {
  			string prefix;
  			for(char c : words[i]) {
  				prefix += c;
  				answers[i] += mp[prefix];
  			}
  		}
  		return answers;
    }
};

int main() {
    
}
