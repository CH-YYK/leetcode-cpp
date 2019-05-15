#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>
using namespace std;

class Solution {
public:
    int mincost(vector<int> & price, vector<int>& ticket, int n, int k) {
        prices = price;
        tickets = ticket;
        K = k;
        return dfs(n+1);
    }
private:
    vector<int> prices;
    vector<int> tickets;
    int K;

    int dfs(int n) {
        if(n == 0) 
            return 0;
        if(n == 1) 
            return K;
        int currmin = INT_MAX;
        for(int i = 0; i < prices.size(); i++) {
            if(n < tickets[i]) continue;
            currmin = min(currmin, prices[i] + dfs(n - tickets[i]));
        }
        return currmin;
    }
};

int main() {
    int n, m, k, x, y;
    vector<int> price;
    vector<int> ticket;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        price.push_back(x);
        ticket.push_back(y);
    }
    price.push_back(k);
    ticket.push_back(1);
    int ans = Solution().mincost(price, ticket, 2, 5);
    // cout << n << k;
    cout << ans;
}