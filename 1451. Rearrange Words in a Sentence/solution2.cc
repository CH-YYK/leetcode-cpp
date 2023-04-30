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
    string arrangeWords(string text) {
    	// n <= 10^5
    	// bucket sort
    	text[0] = tolower(text[0]);

    	string word;
    	// stringstream auto split by space
    	stringstream ss(text), rs;
    	map<int, string> mp;
    	while(ss >> word) {
    		mp[word.size()] += word + " ";
    	}

    	for(const auto& pair : mp) 
    		rs << pair.second;

    	string res = rs.str();
    	res.pop_back();
    	res[0] = toupper(res[0]);
    	return res;
    }
};

int main() {
    
}
