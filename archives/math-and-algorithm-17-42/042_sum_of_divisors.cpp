#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using  v = vector<ll>;

void prime(v &a, ll N) {
  vector<bool> tmp(N+1, true);
  ll end = sqrt(N+1)+1;
  for(ll i=2; i<=end; i++) {
    while(!tmp[i] && i<=end) i++;
    for(ll j=2; i*j<=N; j++) tmp[i*j] = false;
  }
  a.empty();
  for(ll i=2; i<=N; i++) if(tmp[i]) a.push_back(i);
}

int main(void) {
  ll N, i, j, n, cnt, s;
  cin >> N;

  v ret(N+1, 1), a;
  prime(a, N);

  for(i=0; i<a.size(); i++) {
    for(j=1; a[i]*j<=ret.size(); j++) {
      n = a[i]*j;
      for(cnt=0; !(n%a[i]); cnt++) n /= a[i];
      ret[a[i]*j] *= cnt+1;
    }
  }

  ll sum = 0;
  for(ll j=1; j<ret.size(); j++) sum += j * ret[j];
  cout << sum << endl;
}


