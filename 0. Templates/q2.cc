#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<int> getPrioritiesAfterExecution(vector<int> &priroties) {
  vector<int> ans;
  map<int, vector<int>, greater<int>> mp;
  for (int i = 0; i < priroties.size(); ++i) {
    if (!mp.count(priroties[i])) {
      mp[priroties[i]] = vector<int>(2, 0);
    }
    mp[priroties[i]][0]++;
    mp[priroties[i]][1] = max(mp[priroties[i]][1], i);
  }

  while (!mp.empty()) {
    auto it = mp.begin();
    int p = it->first;
    int cnt = it->second[0];
    int mi = it->second[1];

    // throw the proc_2s to p/2 bucket
    if (cnt / 2 > 0)
      mp[p / 2][0] += cnt / 2;
    // 1 was left in p bucket
    if (cnt % 2 > 0) {
      mp[p / 2][1] = max(mp[p / 2][1], mi);
    }
    mp.erase(it);
  }
  return ans;
}

int main() {
  vector<int> pri = {6, 6, 6, 1, 2, 2};
  vector<int> ans = getPrioritiesAfterExecution(pri);
  for (int num : ans)
    cout << num << " ";
  return 0;
}