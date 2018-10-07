#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
      if (!s.size()) return 0;

      std::vector<int> Hash(256, -1);

      string::iterator start(s.begin());
      string::iterator last(s.begin());
      int max_len(1);

      while (last != s.end())
      {
        if (Hash[*last] < start - s.begin())
        {
          Hash[*last] = last - s.begin();
          ++last;
          max_len = max(int(last - start), max_len);
        }else
        {
          start = Hash[*last] + 1 + s.begin();
        }
      }
      return max_len;
    }

    int lengthOfLongestSubstring_slideWindow(string s)
    {
      int max_len(0);
      unordered_map<char, int> um;

      string::iterator u = s.begin();
      string::iterator v = s.begin();

      while (v != s.end())
      {
        // v not in set
        if (!um[*v])
        {
          ++um[*v++];
          max_len = max(max_len, int(v-u));
        }else
        //v in set
        {
          um.erase(*u++);
        }
      }

      return max_len;
    }
};

int main(int argc, char const *argv[]) {
  Solution so = Solution();
  string s;
  while(cin >>s)
    cout << so.lengthOfLongestSubstring(s) << endl;
}
