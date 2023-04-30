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
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int sum = accumulate(skill.begin(), skill.end(), 0);

        if(n & 1) return -1;
        if(sum % (n / 2) > 0) return -1;

        int total = sum / (n / 2);

        // todo: hashmap version
        long long res = 0;
        sort(skill.begin(), skill.end());
        int l = 0, r = n - 1;
        while(l < r) {
            int tmpsum = skill[l] + skill[r];
        	int tmp = skill[l++] * skill[r--];
        	if(tmpsum != total) return -1;
        	res += tmp;
        }
        return res;
    }
};


int main() {
    
}
 