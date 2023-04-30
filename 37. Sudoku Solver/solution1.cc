// Hello, this is a CPP leetcode snippet.

#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <functional>
#include <climits>
#include <set>
#include <map>
#include <sstream>

using namespace std;

/*		
ios_base::sync_with_stdio(0); 
cin.tie(NULL);
*/

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
		vector<vector<int>> middle(3, vector<int>(3, 0));
		vector<int> rows(9, 0), cols(9, 0);

		for(int i = 0; i < 9; ++i)
			for(int j = 0; j < 9; ++j) {
				if(board[i][j] == '.') continue;
				int num = board[i][j] - '0';
				rows[i] |= (1 << num);
				cols[j] |= (1 << num);
				middle[i / 3][j / 3] |= (1 << num);
			}
		function<int(int)> findNext = [&](int n) {
			while(n < 81) {
				int i = n / 9;
				int j = n % 9;
				if(board[i][j] != '.')
					n++;
				else
					break;
			}
			return n;
		};
		function<bool(int)>	backtrack = [&](int n){
			if(n == 81) 
                return true;
			int i = n / 9;
			int j = n % 9;
            int nxt = findNext(n + 1);
			for(int num = 1; num <= 9; ++num) {
				if(rows[i] & (1 << num)) continue;
				if(cols[j] & (1 << num)) continue;
				if(middle[i / 3][j / 3] & (1 << num))
					continue;
				rows[i] |= (1 << num);
				cols[j] |= (1 << num);
				middle[i/3][j/3] |= (1 << num);
				board[i][j] = '0' + num;
				if(backtrack(nxt))
					return true;
				rows[i] -= (1 << num);
				cols[j] -= (1 << num);
				middle[i/3][j/3] -= (1 << num);
				board[i][j] = '.';
			}
			return false;
		};
		for(int i = 0; i < 9; ++i)
			for(int j = 0; j < 9; ++j)
				if(board[i][j] == '.') {
					backtrack(i * 9 + j);
					break;
				}
    }
};