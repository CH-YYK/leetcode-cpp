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
    int appendCharacters(string s, string t) {
		// one-pass s to see how many chars in t can be consumed
		int idxt = 0;
		for(char c : s) {
			if(t[idxt] == c)
				idxt++;
		}
		return t.size() - idxt;
    }
};

int main() {
    
}
