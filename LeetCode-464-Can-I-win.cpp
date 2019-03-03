#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canIWin(int M, int T) {
        const int sum = M * (M+1) / 2;
        if(sum < T) return false;
        if(T <= 0) return true;
        m_ = vector<char>(1 << M, 0);
        return canIWin(M, T, 0);
    }
private:
    vector<char> m_;
    bool canIWin(int M, int T, int state) {
        if(T <= 0) return false;
        if(m_[state]) return m_[state] == 1;
        for(int i = 0; i < M; i++){
            if(state & (1 << i)) continue;
            if(!canIWin(M, T-(i+1), state | (1 << i)))
                return m_[state] = 1;
        }
        m_[state] = -1;
        return false;
    }
};

class Solution2 {
public:
    bool canIWin(int M, int T) {
        // backtracking + memo
        // use memo 2^M
        // no memo O(M!) -> O(2^M * M)
        const int sum = M * (M + 1) / 2;
        if (sum < T) return false;
        if (T <= 0) return true;
        m = vector<char>(1 << M, 0);
        return canIWin(M, T, 0);
    }
private:
    vector<char> m; // 0: unknown; 1, can win; -1, cannot win
    bool canIWin(int M, int T, int state) {
        if (T <= 0) return false;
        if (m[state]) return m[state] == 1;
        for (int i = 0; i < M; ++i) {
            if (state & (1 << i)) continue; // i used
            if (!canIWin(M, T - (i + 1), state | (1 << i)))  // 第i位置于1
                // next player cannot win, current player wins
                return m[state] = 1; 
        }
        m[state] = -1;
        return false;
    }
};
