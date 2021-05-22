#include <algorithm> // copy
#include <iostream> // cin, cout, streamsize
#include <iterator> // back_inserter, istream_iterator
#include <limits> // numeric_limits
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <queue>

using namespace std;

int count_number_of_islands(std::vector<std::vector<int>> grid) {
  int m = grid.size(), n = grid[0].size();
  queue<int> bfsq;
  int res = 0;

  vector<int> dirs = {0, 1, 0, -1, 0};

  for(int i = 0; i < m; ++i)
    for(int j = 0; j < n; ++j) {
      if(grid[i][j] == 0) continue;
      if(grid[i][j] == 2) continue;
      bfsq.push(i*n+j);
      while(!bfsq.empty()) {
        int pos = bfsq.front();
        bfsq.pop();

        int x = pos / n, y = pos % n;
        grid[x][y] = 2;

        for (int d = 0; d < 4; ++d) {
          int nx = x + dirs[d], ny = y + dirs[d+1];
          if (nx < 0 || ny < 0 || nx == m || ny == n)
            continue;
          if(grid[nx][ny] == 1)
            bfsq.push(nx * n + ny);
        }
      }
      res++;
    }

  return res;
}

template<typename T>
std::vector<T> get_words() {
  std::string line;
  std::getline(std::cin, line);
  std::istringstream ss{line};
  std::vector<T> v;
  std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
  return v;
}

void ignore_line() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
  int grid_length;
  std::cin >> grid_length;
  ignore_line();
  std::vector<std::vector<int>> grid;
  for (int i = 0; i < grid_length; i++) {
    grid.emplace_back(get_words<int>());
  }
  int res = count_number_of_islands(grid);
  std::cout << res << '\n';
}
