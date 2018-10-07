#include <iostream>
#include <vector>

using namespace std;

/**
** 二分查找算法，并不简单
** 边界条件，值的更新
**/
int binarySearch(std::vector<int> nums, int target)
{
  int low(0);
  int high(nums.size() - 1);
  int mid;

  while (low <= high)  // 符号
  {
    mid = (low + high) / 2;
    if (nums[mid] == target)
    {
      return mid;
    }
    else if (nums[mid] < target)
    {
      low = mid + 1; // 更新
    }
    else
    {
      high = mid - 1;
    }
  }
  return -1;
}

int main()
{
    int a[10] = {1,12,14,15,16,75,133,145,155,166};
    std::vector<int> v(a, a + 10);
    cout << binarySearch(v,165);
}
