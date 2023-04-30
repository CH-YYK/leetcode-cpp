#include <vector>

using namespace std;

struct compGreater {
    bool operator()(const vector<int> &lhs, const vector<int> &rhs){
         return lhs[2] < rhs[2];
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        for(vector<int> &i:points) i.push_back(distance(i));
        sort(points.begin(), points.end(), compGreater());
        vector<vector<int>> res(points.begin(), points.begin()+K);
        for(vector<int> &i:res) i.pop_back();
        return res;
    }

    int distance(vector<int> &coord){
        return coord[0] * coord[0] + coord[1] * coord[1];
    }
};