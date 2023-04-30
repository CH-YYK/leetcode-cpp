// Hello, this is a CPP leetcode snippet.

#include <algorithm>
#include <climits>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> minOperations(string boxes) {
    // O(N^2) is a trivial way
    // try thinking about a O(N) method
    // transmitting the state from left to right
    // each state may have <curr steps, N>, increment
    // dp[i] = <steps, N>, steps: cumulative steps and N: number of 1s
    // dp[i] = dp[i-1] + N[i-1]
    int n = boxes.size();

    vector<int> leftNumbers(n, 0), rightNumbers(n, 0);
    vector<int> leftSteps(n, 0), rightSteps(n, 0);
    vector<int> answers(n);

    for (int i = 0; i < n; ++i) {
      leftNumbers[i] = boxes[i] == '1';
      if (i > 0) {
        leftSteps[i] = leftSteps[i - 1] + leftNumbers[i - 1];
        leftNumbers[i] += leftNumbers[i - 1];
      }
    }
    for (int i = n - 1; i >= 0; --i) {
      rightNumbers[i] = boxes[i] == '1';
      if (i < n - 1) {
        rightSteps[i] = rightSteps[i + 1] + rightNumbers[i + 1];
        rightNumbers[i] += rightNumbers[i + 1];
      }
    }
    for (int i = 0; i < n; ++i) {
      answers[i] = leftSteps[i] + rightSteps[i];
    }
    return answers;
  }
};

int main() {}
