#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(void) {
  ll N, X;
  cin >> N >> X;

  ll mn = INT64_MAX;
  ll base = 0;
  ll a, b;
  for(ll i=1; i<=N; i++) {
    cin >> a >> b;
    base += a+b;
    mn = min(mn, base+(X-i)*b);
    if (i >= X) break;
  }

  cout << mn << endl;
  return 0;
}

