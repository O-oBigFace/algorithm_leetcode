#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B)
    {
      int m(A.size());
      int n(B.size());

      // 保证m < n
      if(m > n) return findMedianSortedArrays(B, A);

      int low(0);
      int high(m);
      int half((m + n + 1) / 2);

      while (low <= high) {
        int i((low + high) / 2);
        int j(half - i);

        // i过大
        if(i > 0 && A[i - 1]  > B[j])
        {
          high = i - 1;
        }else if(i < m && A[i] < B[j - 1])
        {
          low = i + 1;
        }else
        {
          double left_max(0.0);
          if (i == 0)
          {
            left_max = B[j - 1];
          }else if (j == 0)
          {
            left_max = A[i - 1];
          }else
          {
            left_max = max(A[i - 1], B[j - 1]);
          }

          if ((m + n) % 2 == 1)
          {
            return left_max;
          }

          double right_min(0.0);
          if(i == m)
          {
            right_min = B[j];
          }else if(j == n)
          {
            right_min = A[i];
          }else{
            right_min = min(A[i], B[j]);
          }
          return (left_max + right_min) / 2.0;
        }
      }

    }

};

int main(int argc, char const *argv[]) {
  const int len_a = 2;
  const int len_b = 4;
  int a[len_a] = {1, 5};
  int b[len_b] = {2, 3,4, 6};
  std::vector<int> nums1(a, a + len_a);
  std::vector<int> nums2(b, b + len_b);
  Solution s = Solution();
  cout << s.findMedianSortedArrays(nums1, nums2) << endl;
  return 0;
}
