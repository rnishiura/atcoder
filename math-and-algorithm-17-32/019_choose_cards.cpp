// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_s

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

  long num[3]; for(int i=0; i<3; i++) num[i] = 0;
  for (int i=0; i<n; i++) {
    cin >> a;
    num[a-1]++;
  }

  // cout << num[0] << num[1] << num[2] << endl;
  
  cout << (num[0]*(num[0]-1) + num[1]*(num[1]-1) + num[2]*(num[2]-1)) / 2 << endl;

  return 0;
}

int main(void) {
  // return debug();
  return release();
}