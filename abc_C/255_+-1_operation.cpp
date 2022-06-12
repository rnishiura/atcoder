#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(void) {
  ll X, A, D, N;
  cin >> X >> A >> D >> N;

  ll ans;
  if (D == 0) {
    ans = abs(X - A);
  } else {
    ll K = (X - A) / D;
    if (K < 0) {
      ans = abs(X - A);
    } else if (K > N - 1) {
      ans = abs(X - A - (N-1)*D);
    } else {
      ans = 1000000000;
      for(ll i=-2; i<=2; i++) {
        ans = min(ans, abs(X - A - (K+i)*D));
      }
    }
  }
  printf("%lld\n", ans);
  // cout << ans << endl;
}
