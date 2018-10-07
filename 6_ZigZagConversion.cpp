#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
      if (numRows < 2) return s;
      string lines[50001];
      // std::vector<string> lines(min(s.size(), numRows));
      int turn = s.size() / (2 * numRows - 2) + 1;

      // a turn
      for (size_t i = 0; i < turn; i++) {
        // a line
        for (size_t j = 0; j < numRows; j++) {
          size_t upperBound = s.size();
          size_t index_1 = i * (2 * numRows - 2) + j;
          if (index_1 < upperBound) {
            lines[j].push_back(s[index_1]);
          }
          if (j == 0 || j == numRows - 1) continue;

          size_t index_2 = (i + 1) * (2 * numRows - 2) - j;
          if(index_2 < upperBound){
            lines[j].push_back(s[index_2]);
          }
        }
      }

      for (size_t i = 0; i < numRows; i++) {
        lines[numRows] += lines[i];
      }

      return lines[numRows];
    }
};

int main(int argc, char const *argv[]) {
  Solution so;
  string s;
  int n;
  while (cin >> s) {
    cin >> n;
    std::cout << so.convert(s, n) << '\n';
  }
  return 0;
}
