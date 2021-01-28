#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>


using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        // find min index
        int minIndex = 0;
        int min = INT_MAX;
        int n = ratings.size();
        
        for(int i = 0; i < n; i++) {
            if(ratings[i] >= min) continue;
            min = ratings[i];
            minIndex = i;
        }

        vector<int> candies(n, 1);
        for(int i = minIndex+1; i < n; i++) {
            if(ratings[i] > ratings[i-1]) candies[i]++;
        }

        for(int i = minIndex-1; i >= 0; i--) {
            if(ratings[i] > ratings[i+1]) candies[i]++;
        }

        for(int i = n-1; i > minIndex; i--) {
            if(ratings[i] > ratings[i+1]) candies[i]++;
        }

        for(int i = 0; i < minIndex; i++) {
            if(ratings[i] > ratings[i-1]) candies[i]++;
        }

        int sum = 0;
        for_each(candies.begin(), candies.end(), [&](const int x) {sum+=x;});
        return sum;
    }
};


class Solution2 {
 public:
  int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candies(n, 1);  // initialize all to 1 since each of them must have at least 1

    for(int i = 1; i < n; ++i) {  // go from left to right and add candies to children if necessary
      if(ratings[i] > ratings[i-1]) 
        candies[i] = candies[i-1] + 1;  
    }

    for(int i = n-1; i >= 0; --i) {  // go from right to left and add candies if necessary
      if(ratings[i] > ratings[i+1] && candies[i] <= candies[i+1]) 
        candies[i] = candies[i+1] + 1;
    }

    int sum_ = 0;
    for_each(candies.begin(), candies.end(), [&](int x) {sum_+=x;});
    return sum_;
  }
}