#include <bits/stdc++.h>
#define rep(x, n)      for(ll x=0; x<n; x++)
#define repi(x, a, b)  for(ll x=a; x<b; x++)
#define rrep(x, n)     for(ll x=n-1; x>=0; x--)
#define rrepi(x, a, b) for(ll x=b-1; x>=a; x--)
#define MOD 998244353
#define LL_MAX_S (1LL<<62)
#define DOUBLE_MAX_S ((double)LL_MAX_S)
#define square(z) ((z)*(z))
#define contains(x, s) (s.find(x) != s.end())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mnl (N, i) ((N+i)/i) 
#define mnle(N, i) ((N+i-1)/i) 
#define mnse(N, i) ((N)/i) 
#define mns (N, i) ((N-1)/i) 
#define ss(i) (i>=s.size() ? s[s.size()-1] : s[i])
#define endl '\n'
#define print(z) cout << (z) << endl
#define print2(x, y) cout << (x) << " " << (y) << endl
using namespace std;
using ll  = long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vp  = vector<pair<ll, ll>>;
using vvp = vector<vp>;


int main(void) {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll t; cin >> t;
  ll n, c, d;
  rep(i, t) {

    cin >> n >> c >> d;
    v a(n);
    rep(j, n) cin >> a[j];

    ll max_val = 0;
    ll sum_val = 0;
    for(auto v: a) {
      max_val = max(max_val, v);
      sum_val += v;
    }
    if(max_val*d < c) {
      print("Impossible");
      continue;
    }

    v s(n+1, 0);
    sort(a.rbegin(), a.rend());
    repi(j, 1, n+1) s[j] = a[j-1] + s[j-1];


    if(ss(d) >= c) {
      print("Infinity");
      continue;
    }

    rep(k, d) {
      ll ck = d/(k+1)*ss(k+1) + ss(d%(k+1));
      if(ck < c) {
        print(k-1);
        break;
      }
    }
  }

  
}
