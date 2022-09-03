#include <bits/stdc++.h>
#define square(z) ((z)*(z))
#define print(z) cout << z << endl;
#define MOD 998244353
using namespace std;
using  ll = long long;
using   v = vector<ll>;
using  vv = vector<vector<ll>>;

int main(void) {
  ll N; 
  cin >> N;

  v A(N); 
  for(auto& a: A) cin >> a;

  vector<vv> hist;
  vv p, q, init;
  ll cnt = 0, b;

  for(ll n=1; n<=N; n++) {
    hist = vector<vv>();
    init = vv(n+1, v(n, 0));
    init[0][0] = 1;
    hist.push_back(init);

    for(auto a: A) {
      b = a % n;
      q = hist.back();
      p = init;
      for(ll i=1; i<=n; i++) 
        for(ll j=0; j<n; j++) {
          p[i][j] = q[i][j] + q[i-1][(j-b+n)%n];
          p[i][j] %= MOD;
        }
      hist.push_back(p);
    }
    cnt += p[n][0];
    cnt %= MOD;
  } 
  cout << cnt << endl;
}
