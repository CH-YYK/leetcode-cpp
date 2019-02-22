#include <iostream>
#include "Solution.h"
#include "Solution2.h"
#include <vector>

using namespace std;

int main() {
    int array[] = {2,0,2,1,1,0};
    vector<int> nums(array, array+ sizeof(array)/ sizeof(array[0]));
    for(int i:nums) cout << " " << i;
    cout << endl;

    Solution2().mergeSort(nums);
    for(int i:nums) cout << " " << i;
    cout << endl;
    return 0;
}