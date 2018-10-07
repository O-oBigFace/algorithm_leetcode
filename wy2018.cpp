#include <iostream>
#include <math>

using namespace std;

int trans(double x, double y, double &a, double &b)
{
  int aa(a), bb(b);
  aa = -(b - y) + x;
  bb = (a - x) + y;
  a = aa;
  b = bb;
  cout << a << ' ' << b;
  return 0;
}

double model(double a1, double b1, double a2, double b2)
{
  return sqrt((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2));
}

double dot_mut(double a1, double b1, double a2, double b2)
{
  return (a1 * a2 + b1 * b2);
}

bool isOK(double a[4], double b[4])
{
  int va[3], vb[3];
  va[0] = a[0] - a[1];
  vb[0] = b[0] - b[1];
  va[1] = a[0] - a[2];
  vb[1] = b[0] - b[2]

}

int f()
{
  int k = 4;
  double x[4], y[4], a[4], b[4];
  for(int i(0); i < k; ++i)
  {
    cin >> x[i];
    cin >> y[i];
    cin >> a[i];
    cin >> b[i];
    ++k;
  }




}

int main()
{
  double a(1), b(1);
  trans(0, 0, a, b);
  return 0;
}
