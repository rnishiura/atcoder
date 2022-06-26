#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll cmb(ll n, ll r) {
  if (r == 0 || n == r) {
    return 1;
  }
  return cmb(n-1, r-1) + cmb(n-1, r);
}

int main(void) {
  cout << cmb(100, 40) << endl;
}
