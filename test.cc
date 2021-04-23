#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

unordered_map<string, priority_queue<string, vector<string>>> vec;
vector<string> res;

void dfs(string& s, vector<string>& rr) {
  while(!vec.empty() && vec[s].size() > 0) {
    string temp = vec[s].top();
    vec[s].pop();
    dfs(temp, rr);
  }
  rr.push_back(s);
}

vector<string> findItinerary1(vector<vector<string>> & tickets) {
  for(vector<string>& s : tickets)
    vec[s[0]].push(s[1]);
  string s("JFK");

  dfs(s, res);
  reverse(res.begin(), res.end());
  return res;
}

int main() {
  vector<vector<string>> tic = {{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};
  vector<string> ga = findItinerary1(tic);
  for(int i = 0; i < ga.size(); ++i)
    cout << ga[i] << " " << endl;
  return 0;
}
