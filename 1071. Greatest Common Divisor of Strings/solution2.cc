// Hello, this is a CPP leetcode snippet.

#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/*
ios_base::sync_with_stdio(0);
cin.tie(NULL);
*/

class Solution {
 public:
  string gcdOfStrings(string str1, string str2) {
    // find an x that divides str1 and str2
    // find common prefix
    // use GCD directly after confirming that str1 and str2 
    // are formed by some "pattern" periodically
    if(str1 + str2 != str2 + str1)
    	return "";

    auto gcd = [&](int a, int b) {
    	while(b != 0)
    		swap(b, a %= b);
    	return a;
    };
    int n1 = str1.size(), n2 = str2.size();
    int len = 0;
    if(n1 >= n2) 
    	len = gcd(n1, n2);
    else 
    	len = gcd(n2, n1);
    return str1.substr(0, len);
  }
};