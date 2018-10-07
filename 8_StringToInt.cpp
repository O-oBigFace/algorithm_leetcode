#include <iostream>
#include <climits>
// #include <iterator>

using namespace std;

class Solution {
public:

    // 实现trim功能
    string trim(const string &s){
      string::const_iterator si = s.begin();
      while (si != s.end() && isspace(*si))
        ++si;

      string::const_reverse_iterator sr = s.rbegin();
      // if sr.base() == si : *(si - 1) = *sr
      while (sr.base() != si && isspace(*sr))
        ++sr;

        return string(si, sr.base());
    }

    int myAtoi(string str){
        int res(0);
        string s(trim(str));
        if (s.size() < 1) {
          return 0;
        }

        int sign = 1;
        int digit(0);

        // 判断符号
        string::iterator it_str(s.begin());
        if (*it_str == '-') {
          sign = -1;
          ++it_str;
        }else if (*it_str == '+') {
          ++it_str;
        }

        while (isdigit(*it_str)) {
          digit = *it_str++  - '0';

          if (res > INT_MAX / 10 || res == INT_MAX / 10 && digit > 7) {
            return sign == 1 ? INT_MAX : INT_MIN;
          }

          res = res * 10 + digit;
        }

        return res * sign;
    }

    int myAtoi_no(string str) {
      int res(0);
      string s(trim(str));
      string::iterator it = s.begin();

      bool isNeg = false;
      if (*it == '-') {
        isNeg = true;
        ++it;
      }

      while (it != s.end()) {
        int i = *it++ - '0';

        // 不是数字
        if (i < 0 || i > 9) break;

        if (it - s.begin() + 1 - isNeg > 9){
          if (res > 214748364){
            return isNeg? -2147483648 : 2147483647;
          }else if (res == 214748364) {
            if (!isNeg && i <= 7){
              return 10 * res + i;
            }
            if (!isNeg && i < 8){
              return -10 * res - 8;
            }
            return isNeg? -2147483648 : 2147483647;
          }else{
            res = 10 * res + i;
            break;
          }

        }

        res = 10 * res + i;
      }
      return isNeg ? -res : res;
    }
};

int main(int argc, char const *argv[]) {
  Solution so;
  string s;
  while (cin >> s) {
    cout << so.myAtoi(s) << endl;
  }
  return 0;
}
