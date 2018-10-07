#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxArea(std::vector<int>& v)
{
  int result = 0;
  for(vector<int>::iterator iter(v.begin()); iter != v.end(); ++iter)
  {
    for(vector<int>::iterator jter(v.begin()); jter != iter; ++jter)
    {
      int area(min(*iter, *jter) * (iter - jter));
      result = area > result ? area: result;
    }
  }
  return result;
}

int main()
{
  int a[9] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  std::vector<int> v(a, a+9);
  cout << maxArea(v);
}
