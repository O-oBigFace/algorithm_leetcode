#include <iostream>
// #include <cstdio>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
      if(!s.size()) return s;
      int max_len = 0;
      string s_max("");
      for(string::iterator it(s.begin()); it != s.end(); ++it)
      {
        int len_half = 0;
        while (len_half <= it - s.begin() && len_half + it < s.end())
        {
          // 如果是回文
          if (*(it + len_half) == *(it - len_half))
          {
            int len = 1 + 2 * len_half;
            if (max_len <= len)
            {
              max_len = len;
              // 利用迭代器赋值
              s_max.assign(it - len_half, it + len_half + 1);
            }
            ++len_half;
          }else
          {
            break;
          }
        }
      }

      for(string::iterator it(s.begin()); it != s.end() - 1; ++it)
      {
        // 相同的两个字符作为中心
        if (*it == *(it + 1))
        {
          int len_half(0);
          while (it - len_half >= s.begin() && it + len_half + 1 < s.end())
          {
            // yes
            if (*(it - len_half) == *(it + len_half + 1))
            {
              int len = 2 + len_half * 2;
              // update
              if (max_len <= len)
              {
                max_len = len;
                s_max.assign(it - len_half, it + len_half + 2);
              }
              ++len_half;
            }else
            // no
            {
              break;
            }
          }
        }
      }

      return s_max;
    }
};

int main() {
  Solution so = Solution();
  string s("");
  while(cin >> s)
  {
    cout << so.longestPalindrome(s) <<endl;
  }

  return 0;
}
