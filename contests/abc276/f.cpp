#include <bits/stdc++.h>
#define rep(x, n)      for(ll x=0; x<n; x++)
#define repi(x, a, b)  for(ll x=a; x<b; x++)
#define rrep(x, n)     for(ll x=n-1; x>=0; x--)
#define rrepi(x, a, b) for(ll x=b-1; x>=a; x--)
#define contains(x, s) (s.find(x) != s.end())
#define square(z) ((z)*(z))
#define MOD 998244353
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define print(z) cout << (z) << endl
#define print2(x, y) cout << x << " " << y << endl
using namespace std;
using ll  = long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vp  = vector<pair<ll, ll>>;
using vvp = vector<vp>;

ll inv(ll n) {
  if(n == 1) {
    return 1;
  } else {
    return MOD - inv(MOD%n) * (MOD/n) % MOD;
  }
}

ll ans(ll x, ll y) {
  return (inv(x) + y%MOD) %MOD;
}

int main(void) {
  ll N;
  cin >> N;

  v A(N);
  rep(i, N) cin >> A[i];

  v S(N+1, 0);
  repi(i, 1, N+1) {
    S[i] = S[i-1] + A[i-1];
  }

  list<ll> ms;
  ms.insert(ms.begin(), A[0]);
  print(A[0]);

  repi(i, 1, N) {
    ll invX = inv(i+1);
    invX *= invX;
    invX %= MOD;

    ll r;
    auto it=lower_bound(ms.begin(), ms.end(), A[i]);
    ll l = it-ms.begin();
    r = l*A[i]+S[i]-S[l];
    // ms.insert(itA[i]);

    print((invX * (2*r-A[i])) % MOD);
  }
}