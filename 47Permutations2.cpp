#include <iostream>
#include <vector>

using namespace std;

int swap(std::vector<int> &v, int i, int j)
{
  int temp(v[i]);
  v[i] = v[j];
  v[j] = temp;
  return 0;
}

/**
**  输入：原数组，当前位置的索引
**/
vector<vector<int> > func(std::vector<int> nums, int index)
{
  int length(nums.size());

  vector<vector<int> > res;

  // 如果数组只包含一个元素，则返回本身
  if(index == length - 1)
  {
    std::vector<int> v(nums.begin() + index, nums.end());
    res.push_back(v);
    return res;
  }

  //如果数组包含两个元素，则返回两个元素的全排列
  if(index == length - 2)
  {


    std::vector<int> v(nums.begin() + index, nums.end());
    res.push_back(v);

    // 改动2
    if(nums[index] == nums[length - 1]) return res;

    swap(v, 0, 1);
    res.push_back(v);
    return res;
  }

  //如果数组包含元素个数大于2,则递归
  // i：指针； index：当前位置
  for(int i(index); i != length; ++ i)
  {
    int isIgnore = false;
    // 改动之一
    for(int j(index) ; j < i; ++j){
      if(nums[i] == nums[j]){
        isIgnore = true;
        break;
      }
    }

    if(isIgnore) continue;

    swap(nums, i, index);
    std::vector<std::vector<int> > vv(func(nums, index + 1));
    for(vector<vector<int> >::iterator iter(vv.begin()); iter != vv.end(); ++ iter)
    {
      iter->push_back(nums[index]);
    }
    res.insert(res.end(), vv.begin(), vv.end());
    swap(nums, i, index);
  }
  return res;
}

/**
** 输入数组，输出全排列
**/
vector<vector<int> > permuteUnique(vector<int>& nums)
{
  std::vector<std::vector<int> > result = func(nums, 0);
  return result;
}



int main()
{
  int a[5] = {1, 1, 2, 2, 5};
  std::vector<int> v(a, a + 4);
  std::vector<std::vector<int> > res(permuteUnique(v));
  // cout << res[0].size() << endl;
  for (size_t i = 0; i < res.size(); i++) {
    for (size_t j = 0; j < res[0].size(); j++) {
      cout << res[i][j] << ' ';
    }
    cout << endl;
  }

}
