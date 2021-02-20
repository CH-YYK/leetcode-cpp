#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    // Two mappings: bus -> stops and stops -> buses
    //          buses determined the edges 
    //          stops determined the nodes
    //          from each step -> for_each bus -> for each stop
    //          stops could be revisited
    //          buses should be unique.
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if(S == T) return 0;

        unordered_map<int, vector<int>> m;
        for(int i = 0; i < routes.size(); i++) 
            for(auto j : routes[i]) 
                m[j].push_back(i);

        vector<int> visited(routes.size(), 0);
        queue<int> q({S});
        int buses = 0;

        while(!q.empty()) {
            int size = q.size();
            buses++;
            while(size-- > 0) {
                int curr = q.front(); q.pop();
                for(const int bus : m[curr]) {
                    if(visited[bus] == 1) continue;
                    visited[bus] = 1;
                    for(int stop : routes[bus]) {
                        if(stop == T) return buses;
                        q.push(stop);
                    }
                }
            }
        }
        return -1;
    }
};
