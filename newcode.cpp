// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numStarsInArea(int a1, int a2, int b1, int b2, vector<vector<int>>& stars) {
        int num = 0;
        for(auto star : stars) {
            if(star[0] >= a1 && star[0] <= a2 && star[1] >= b1 && star[1] <= b2)
                num++;
        }
        return num;
    }
};


int main() {
    int a,b,n,m;
    cin >> n;
    vector<vector<int>> stars;
    for(int i = 0; i < n; i++) {// 注意，如果输入是多个测试用例，请通过while循环处理多个测试用例
        cin >> a >> b;
        stars.push_back({a, b});
    }
    
    cin >> m;

    int a1, b1, a2, b2;
    for(int i = 0; i < m; i++) {
        cin >> a1 >> b1 >> a2 >> b2;
        cout << Solution().numStarsInArea(a1, a2, b1, b2, stars) << endl;
    }
}