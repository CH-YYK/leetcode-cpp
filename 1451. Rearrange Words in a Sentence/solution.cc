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

using namespace std;

class Solution {
public:
    string arrangeWords(string text) {
    	// n <= 10^5
    	// bucket sort
  		vvector<string>> cnts(100000);
  		text += ' ';

  		string w;
  		for(char c : text) {
  			if(c == ' ')
  				cnts[w.size()].emplace_back(move(w));
  			else 
  				w += tolower(c);
  		}

  		string res;
  		for(int i = 0; i < cnts.size(); ++i)
  			if(cnts[i].empty()) continue;
  			else {
  				for(string& t : cnts[i]) {
  					if(res.empty()) {  					
  						t[0] = toupper(t[0]);
  					}
  					res += t[0];
  					res += ' ';
  				}  				
  			}
  		res.pop_back();
  		return res;
    }
};

int main() {
    
}
