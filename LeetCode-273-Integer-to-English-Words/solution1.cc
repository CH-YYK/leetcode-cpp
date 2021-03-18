#include <string>
#include <vector>

using namespace std;

/* process 3-digit by 3-digit
 */
class Solution {
public:
  string numberToWords(int num) {
    return "";
  }
private:
  vector<string> tenToTwenty = {"Ten","Eleven", "Twelve", "Thirteen", "Fourteen",
                                "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nighteen"};
  vector<string> tens = {"", "", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty",
                         "Ninety"};
  vector<string> digits = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
};
