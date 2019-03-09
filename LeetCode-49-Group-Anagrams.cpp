#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(string &i : strs) {
            string t = i;
            sort(t.begin(), t.end());
            if(map.count(t)) map[t].push_back(i);
            else map[t] = vector<string>({i});
        }
        vector<vector<string>> res;
        for(auto p : map) 
            res.push_back(p.second);
        return res;
    }
};