// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_q

#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

long gcd(long a, long b) {
  long ret = 0;
  if(a>b) { a=a+b, b=a-b; a=a-b; }
  for(long k=1; k<=sqrt(a); k++) {
    if(a % k == 0) {
      if(b % k == 0) {
        ret = max(ret, k);
      }
      if(b % (a/k) == 0) {
        ret = max(ret, a/k);
      }
    }
  }
  return ret;
}

long lcm(long a, long b) {
  return a / gcd(a, b) * b;
}

long lcm_of_n_long(long *a, int l) {
  long ret = lcm(a[0], a[1]);
  for(int i=2; i<l; i++) {
    ret = lcm(ret, a[i]);
  }
  return ret;
}

int main(void) {
  int n;
  cin >> n;
  long a[n];
  for (int i=0; i<n; i++) cin >> a[i];

  cout << lcm_of_n_long(a, n) << endl;

  return 0;
}
