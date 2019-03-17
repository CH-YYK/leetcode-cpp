#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> findMax(vector<vector<int>> &nums) {
        sort(nums.begin(), nums.end(), [](vector<int> &lhs, vector<int> &rhs){return lhs[0] < rhs[0];});

        vector<vector<int>> res;
        res.push_back(nums.back());
        nums.pop_back();
        int i = nums.size() - 1;
        while(i >= 0) {
            if(nums[i][1] > res.back()[1]) res.push_back(nums[i]);
            i--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

struct Point {
    int x;
    int y;
};

bool comp(const Point lhs, const Point rhs){
    return lhs.x > rhs.x;
};

int main() {
    vector<vector<int>> nums;
    int num;
    cin >> num;
    Point point[num];
    for(int i = 0; i < num; i++) {
        scanf("%d %d", &point[i].x, &point[i].y);
    }
    
    // sort
    sort(point, point + num, comp);

    // generate new to store output
    int len = 1;
    Point curY = point[0];
    for(int i = 1; i < num; i++){
        if(point[i].y > curY.y){
            point[len] = point[i];
            curY = point[len];
            len++;
        }
    }

    for(int i = len - 1; i >= 0; i--) {
        printf("%d %d\n", point[i].x, point[i].y);
    }
    return 0;
}