#include <vector>
#include <functional>
#include <string>
using namespace std;

class Solution {
public:
  int ways(vector<string>& pizza, int K) {
    constexpr int kMod = 1e9 + 7;
    const int M = pizza.size();
    const int N = pizza[0].size();

    vector<vector<int>> A(M+1, vector<int>(N+1));
    for(int y = 0; y < M; ++y)
      for(int x = 0; x < N; ++x)
        A[y+1][x+1] = A[y+1][x] + A[y][x+1] + (pizza[y][x] == 'A') - A[y][x];
    auto hasApples = [&](int x1, int y1, int x2, int y2) {
                       return (A[y2+1][x2+1] - A[y2+1][x1] - A[y1][x2+1] + A[y1][x1]) > 0;
                     };
    // state: i, j, k
    vector<vector<vector<int>>> cache(M, vector<vector<int>>(N, vector<int>(K, -1)));
    function<int(int, int, int)> dp = [&](int m, int n, int k) { // # of ways to cut pizza[m:M][n:N] with k cuts
                                        if(k == 0) return (int)hasApples(n, m, N-1, M-1);
                                        int& ans = cache[m][n][k];
                                        if(ans != -1) return ans;
                                        ans = 0;
                                        for(int y = m; y < M-1; ++y)
                                          ans = (ans + hasApples(n, m, N-1, y) * dp(y+1, n, k-1)) % kMod;
                                        for(int x = n; x < N-1; ++x)
                                          ans = (ans + hasApples(n, m, x, M-1) * dp(m, x + 1, k-1)) % kMod;
                                        return ans;
                                      };
    return dp(0, 0, K-1);
  }
};
