#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        // This question is similar to find a number that is not in the array.
        // Since we only need any of them, it could be the one that is greater than the max or the one that is less than the min.
        // But it has to be in the range of [0000, 1111], if n = 4.
        //
        // So we always start from [0]{n} and then take the max.
        int n = nums[0].size();
        unordered_set<int> num_int;

        int min_num = 0;
        int max_num = (1 << n) - 1;

        for (auto &num : nums)
        {
            num_int.insert(str_to_int(num));
        }
        for (auto &num : num_int)
        {
            if (num < max_num && !num_int.count(num + 1))
                return int_to_str(num + 1, n);
            if (num > min_num && !num_int.count(num - 1))
                return int_to_str(num - 1, n);
        }
        return "";
    }

private:
    int str_to_int(const string &str)
    {
        int num = 0;
        for (auto &c : str)
        {
            num = num * 2 + (c - '0');
        }
        return num;
    }
    string int_to_str(const int &num, const int &n)
    {
        string str = string(n, '0');
        int num_copy = num;
        for (int i = n - 1; i >= 0; i--)
        {
            str[i] = '0' + num_copy % 2;
            num_copy /= 2;
        }
        return str;
    }
};