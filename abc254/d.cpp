#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
  ll N;
  cin >> N;

  ll cnt_al = 0;
  for(ll i=1; i<=N; i++) {
    ll k = i;
    ll cnt = 0;
    for(ll d=2; d*d<=k; d++) {
      while(k % (d*d) == 0) {
        k /= d*d;
      }
    }
    for(ll d=1; k*d*d <= N; d++) {
      cnt++;
    }
    cnt_al += cnt;
  }

  cout << cnt_al << endl;
  return 0;
}

