#include <iostream>
#include <vector>

using namespace std;


void nextPermutation(vector<int>& nums)
{
  bool isChanged = false;
  for (std::vector<int>::reverse_iterator riter(nums.rbegin() + 1); (riter != nums.rend()) && !isChanged; ++riter)
  {
    // 寻找从尾至头的顺序关系（反方向而言）
    if(*riter >= *(riter - 1)) continue;

    // 在riter处出现逆序关系, 则先对之前的元素排序

    for(std::vector<int>::reverse_iterator rjter(nums.rbegin()), rkter(riter - 1); rjter < rkter; ++rjter, --rkter)
    {
      int temp = *rkter;
      *rkter = *rjter;
      *rjter = temp;
    }

    // 交换恰好大于riter的元素
    std::vector<int>::reverse_iterator rjter(riter-1);
    while (*rjter <= *riter) --rjter;
    int temp = *riter;
    *riter = *rjter;
    *rjter = temp;


    isChanged = true;
  }


  // 如果未改变，则逆序
  if(!isChanged)
  {
    size_t length = nums.size();
    for(size_t i(0); i < length / 2; ++i)
    {
      int temp (nums[i]);
      nums[i] = nums[length - 1 - i];
      nums[length - 1 - i] = temp;
    }
  }

}


int main(int argc, char const *argv[])
{
  int a[3] = {3,2,1};
  std::vector<int> v(a, a + 3);
  nextPermutation(v);
  for(size_t i(0); i != v.size(); ++i)
  {
    cout << v[i] << ' ';
  }

  return 0;
}


// #include <iostream>
// #include <vector>
//
// using namespace std;
//
//
// void nextPermutation(vector<int>& nums)
// {
//   bool isChanged = false;
//   for (std::vector<int>::reverse_iterator riter(nums.rbegin()); (riter != nums.rend() - 1) && !isChanged; ++riter)
//   {
//     if(*riter > *(riter + 1))
//     {
//       int temp = (*riter);
//       *riter = *(riter + 1);
//       *(riter + 1) = temp;
//       isChanged = true;
//     }
//   }
//
//
//   // 如果未改变，则逆序
//   if(!isChanged)
//   {
//     size_t length = nums.size();
//     for(size_t i(0); i < length / 2; ++i)
//     {
//       int temp (nums[i]);
//       nums[i] = nums[length - 1 - i];
//       nums[length - 1 - i] = temp;
//     }
//   }
//
// }
//
//
// int main(int argc, char const *argv[])
// {
//   int a[2] = {1, 2};
//   std::vector<int> v(a, a + 2);
//   nextPermutation(v);
//   for(size_t i(0); i != v.size(); ++i)
//   {
//     cout << v[i] << ' ';
//   }
//
//   return 0;
// }
