// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_r

#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int debug(void) {
  int n;
  cin >> n;

  cout << n * n << endl;

  return 0;
}

int release(void) {
  long n; int a;
  cin >> n;

  long num[4]; for(int i=0; i<4; i++) num[i] = 0;
  for (int i=0; i<n; i++) {
    cin >> a;
    // cout << a / 100 - 1 << endl;
    int idx = a / 100 - 1;
    // cout << idx << endl;
    num[idx]++;
  }
  
  cout << num[0] * num[3] + num[1] * num[2] << endl;

  return 0;
}

int main(void) {
  return debug();
  // return release();
}