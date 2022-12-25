#include <bits/stdc++.h>
#define MOD 998244353
#define LL_MAX_S  (1LL<<62)
#define DBL_MAX_S ((double)LL_MAX_S)
#define rep(x, n)      for(ll x=0; x<n; x++)
#define repi(x, a, b)  for(ll x=a; x<b; x++)
#define rrep(x, n)     for(ll x=n-1; x>=0; x--)
#define rrepi(x, a, b) for(ll x=b-1; x>=a; x--)
#define square(z) ((z)*(z))
#define contains(x, s) (s.find(x) != s.end())
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define unordered_multiset multiset
#define unordered_set set
#define unordered_map map
#define mnl(N, i)  ((N+i)/i) 
#define mnle(N, i) ((N+i-1)/i) 
#define mnse(N, i) ((N)/i) 
#define mns(N, i)  ((N-1)/i) 
#define endl '\n'
#define print(z)        cout << (z) << endl
#define print2(y, z)    cout << (y) << ' '; print(z)
#define print3(x, y, z) cout << (x) << ' '; print2(y, z)
using namespace std;
using ll  = long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vp  = vector<pair<ll, ll>>;
using vvp = vector<vp>;

void update(v& tree, ll m, ll pos, ll x) {
  ll i = m-1+pos;
  tree[i] += x;
  while(i >= 2) {
    i /= 2;
    tree[i] = tree[2*i] + tree[2*i+1];
  }
}

ll search(v& tree, ll l, ll r, ll a, ll b, ll i) {
  if(l <= a && b <= r) return tree[i];
  if(b <= l || r <= a) return 0;
  ll m = (a+b) / 2;
  return search(tree, l, r, a, m, 2*i) + search(tree, l, r, m, b, 2*i+1);
}

void solve() {
  ll n, q; cin >> n >> q;

  ll m = 1; while(m < n) m <<= 1;

  v tree(2*m, 0);

  ll val;
  repi(i, 1, n+1) {
    cin >> val;
    update(tree, m, i, val);
  }

  ll r, s, t;
  rep(i, q) {
    cin >> r >> s >> t;
    switch(r) {
      case 0:
      update(tree, m, s+1, t);
      break;
      case 1:
      print(search(tree, s+1, t+1, 1, m+1, 1));
      break;
    }
  }
}

int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  ll t = 1; // cin >> t;
  rep(i, t) solve();
}
