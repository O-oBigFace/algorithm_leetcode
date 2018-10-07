#include <iostream>

using namespace std;


/**
** 使 两个用string存储的大整数 相加
**/
string addStrings(string s1, string s2)
{
  string result("");
  int isForward(0);

  int i(s1.size() - 1);
  int j(s2.size() - 1);

  for(i, j; i > -1 || j > -1; --i, --j)
  {

    int num_1(0);
    int num_2(0);

    if(i > -1) num_1 = s1[i] - '0';
    if(j > -1) num_2 = s2[j] - '0';

    //相加 - 剪辑
    int sum = num_1 + num_2 + isForward;
    isForward = sum / 10;
    sum %= 10;
    result  = char(sum + '0') + result;
  }

  if(isForward > 0)
  {
    result = char(isForward + '0') + result;
  }

  return result;
}



int main()
{
  string s1 = "2134213423";
  string s2 = "99999999999999999999999";
  cout << addStrings(s1, s2);
}
