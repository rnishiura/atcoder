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

void solve() {
  ll n, m, k; cin >> n >> m >> k;

  multiset<ll> s, t; 
  ll sum = 0;
  v a(n); 
  rep(i, n) cin >> a[i]; 
  v b(a.begin(), a.begin()+m);
  sort(b.begin(), b.end());

  rep(i, m) { 
    if(i < k) {
    s.insert(b[i]);
    sum += b[i];
  } else {
    t.insert(b[i]);
    }
  }

  cout << sum << " ";

  if(m == k) {
    repi(i, m, n) {
      sum -= a[i-m];
      s.erase(s.find(a[i-m]));
      s.insert(a[i]);
      sum += a[i];
      cout << sum << " ";
    }
    cout << endl;
    return;
  }

  repi(i, m, n) {
    if(contains(a[i-m], s)) {
      sum -= a[i-m];
      s.erase(s.find(a[i-m]));
      if(a[i] <= *t.begin()) {
        s.insert(a[i]);
        sum += a[i];
      } else {
        s.insert(*t.begin());
        sum += *t.begin();
        t.erase(t.begin());
        t.insert(a[i]);
      }
    } else {
      t.erase(t.find(a[i-m]));
      if(a[i] <= *prev(s.end())) {
        t.insert(*prev(s.end()));
        sum -= *prev(s.end());
        s.erase(prev(s.end()));
        s.insert(a[i]);
        sum += a[i];
      } else {
        t.insert(a[i]);
      }
    }
    cout << sum << " ";
  }

  cout << endl;
}

int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  ll t = 1; // cin >> t;
  rep(i, t) solve();
}
