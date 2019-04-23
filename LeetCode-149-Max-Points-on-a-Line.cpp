#include <vector>
#include <iostream>
#include <map>
using namespace std;

struct Line {
    pair<int, int> left;
    pair<int, int> right;
    
    Line(pair<int,int> &x, pair<int,int> &y) {
        if(x.first < y.first) left = x, right = y;
        else right = x, left = y;
    }

    bool isline(pair<int, int> &p) {
        if(p.first > right.first)
            return (p.first + left.first == 2 * right.first) && (p.second + left.second == 2 * right.second);
        else if(p.first < left.first) 
            return (p.first + right.first == 2 * left.first) && (p.second + right.second == 2 * left.second);
        else
            return left.first + right.first == 2 * p.first;
    }

    void add(pair<int, int> &p) {
        if(p.first > right.first) right = p;
        else if(p.first < left.first) left = p;
    }
};

class Solution {
public:
    int maxPoints(vector<vector<int>> &points) {
        int n = points.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            map<pair<int, int>, int> count;
            int same_points = 1;
            int max_points = 0;
            const vector<int> p1 = points[i];
            for(int j = i + 1; j < n; j++) {
                const vector<int> p2 = points[j];
                if(p1[0] == p2[0] && p1[1] == p2[1]) 
                    same_points++;
                else
                    max_points = max(max_points, ++count[getSlope(p1, p2)]);               
            }
            ans = max(ans, same_points + max_points);
        }
        return ans;
    }

private:
    pair<int, int> getSlope(const vector<int> &p1, const vector<int> &p2) {
        const int dx = p2[0] - p1[0];
        const int dy = p2[1] - p1[1];

        // horizontal line
        if(dy == 0) return {p1[0], 0};

        // vertical line
        if(dx == 0) return {0, p1[1]};

        const int d = gcd(dx, dy);
        return {dy / d, dx / d};
    }
    int gcd(int a, int b) {
        return a==0? b : gcd(b % a, a);
    }
};