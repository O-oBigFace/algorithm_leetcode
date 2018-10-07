#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int reverse(int x) {
      int sign = x < 0 ? -1 : 1;
      int res(0);
      int digit(0);

      while (0 != x) {
        digit = (x % 10) * sign;
        x = x / 10;

        if (res > INT_MAX / 10 || res == INT_MAX / 10 && digit > 7) {
          return 0;
          // return sign == 1 ? INT_MAX : INT_MIN;
        }
        res = res * 10 + digit;
      }
      return res * sign;
    }
};

int main(int argc, char const *argv[]) {
  Solution so;
  int n;
  while (cin >> n) {
    cout << so.reverse(n) << endl;
  }
  return 0;
}
