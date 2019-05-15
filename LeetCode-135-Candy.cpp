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