#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        // no limitation on number of flips
        // making a row all 0 or all 1 doesn't really matter.
        // if we make a row all same, then the rest are already determined.
        //
        // so we can try making each row same for once, and check the rest to see
        // how many same rows we get.
        //
        // This way might be too costly, so we probably can get which two rows would
        // be always same. if XOR of row_i and row_j are all 0 or all 1, then row_i
        // and row_j will be same at the same time. Comparing 300 for a row is too
        // large, try merging them to several 64 long numbers, then we'd have 3
        // numbers at most per row.
        int m = matrix.size();
        int n = matrix[0].size();
        // (n + 63) / 64.  if n = 64, then 1, if n < 128, then 2.
        unordered_map<string, int> keys;
        for (int i = 0; i < m; ++i)
        {
            vector<uint64_t> keys1((n + 63) / 64, 0);
            vector<uint64_t> keys2((n + 63) / 64, 0);
            for (int j = 0; j < n; ++j)
            {
                keys1[j / 64] |= ((uint64_t)matrix[i][j] << (j % 64));
                keys2[j / 64] |= ((uint64_t)(matrix[i][j] ^ 1) << (j % 64));
            }
            string key1, key2;
            for (int i = 0; i < keys1.size(); ++i)
            {
                key1 += to_string(keys1[i]) + ",";
                key2 += to_string(keys2[i]) + ",";
            }
            keys[key1]++;
            keys[key2]++;
        }
        int ans = 0;
        for (const auto &[key, count] : keys)
        {
            ans = max(ans, count);
        }
        return ans;
    }
};