#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return dfs(days, 0, costs, 0);
    }
private:
    vector<int> memo;
    // dfs return the costs required to cover the days after days[ind].
    int dfs(vector<int>& days, int ind, vector<int>& costs, int maxDay) {
        if(ind == days.size()) return 0;
        if(maxDay >= days[ind]) 
            return dfs(days, ind+1, costs, maxDay);
        else{
            int cost0 = costs[0] + dfs(days, ind+1, costs, days[ind]);
            int cost1 = costs[1] + dfs(days, ind+1, costs, days[ind] + 6);
            int cost2 = costs[2] + dfs(days, ind+1, costs, days[ind] + 29);
            return max(cost0, max(cost1, cost2));
        }
    }
};

class Solution2 {
    // recursive with memoization
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memo = vector<int>(days.size(), 0);
        return dfs(days, 0, costs, 0);
    }
private:
    vector<int> memo;

    // dfs return the costs required to cover the days after days[ind].
    int dfs(vector<int>& days, int ind, vector<int>& costs, int maxDay) {
        if(ind == days.size()) return 0;
        
        // don't need to buy passes when current day is covered
        if(maxDay >= days[ind])  
            return dfs(days, ind+1, costs, maxDay);
        else if(memo[ind] > 0) return memo[ind];
        else{
            int cost0 = costs[0] + dfs(days, ind+1, costs, days[ind]);
            int cost1 = costs[1] + dfs(days, ind+1, costs, days[ind] + 6);
            int cost2 = costs[2] + dfs(days, ind+1, costs, days[ind] + 29);
            memo[ind] = min(cost0, min(cost1, cost2));
            return memo[ind];
        }
    }
};