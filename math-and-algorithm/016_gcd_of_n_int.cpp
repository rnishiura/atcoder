#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool foreach_divisor_is_factor(long divided[], int n, long divisor) {
  for(int i=0; i<n; i++) {
    if(divided[i] % divisor != 0) return false;
  }
  return true;
}

long gcd_of_multiples(long a[], int l) {
  long ret = 0;

  sort(a, a + l);

  for(long i=1; i<=sqrt(a[0]); i++) {
    if(a[0]%i == 0) {
      if(foreach_divisor_is_factor(a+1, l-1, i)) ret = max(ret, i);
      if(foreach_divisor_is_factor(a+1, l-1, a[0]/i)) ret = max(ret, a[0]/i);
    }
  }
  return ret;
}

int main() {
  int n;
  cin >> n;

  long a[n];
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }

  cout << gcd_of_multiples(a, n) << endl;

  return 0;
}
