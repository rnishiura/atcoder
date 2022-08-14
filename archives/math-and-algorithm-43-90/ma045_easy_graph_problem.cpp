#include <bits/stdc++.h>
#define print(z) cout << z << endl;
#define square(z) ((z)*(z))
#define MOD 998244353
using namespace std;
using  ll = long long;
using   v = vector<ll>;

int main(void) {
  ll N, M;
  cin >> N >> M;
  
  // let's input'em
  v u(2);
  vector<set<ll>> vs(N+1);
  for(ll i=0; i<M; i++) {
    cin >> u[0] >> u[1];
    for(ll j=0; j<2; j++) vs[u[j]].insert(u[1-j]);
  }

  ll cnt = 0;
  for(ll i=1; i<=N; i++) {
    set<ll> s = vs[i];
    s.insert(i);
    auto it = s.begin();
    if(*it < i && *(++it) == i) cnt++;
  }
  
  print(cnt);
}
