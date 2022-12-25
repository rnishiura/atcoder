#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
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

// void solve() {
//   ll n; cin >> n;
//   v a(n); rep(i, n) cin >> a[i];

//   bool dec = false, inc = false;
//   repi(i, 1, n) {
//     if(a[i-1] > a[i]) {
//       dec = true;
//     }
//     if(a[i-1] < a[i]) {
//       inc = true;
//     }
//     if(dec && a[i-1] < a[i]) {
//       ll x = (a[i]+a[i-1])/2;
//       rep(j, n) {
//         a[j] = llabs(a[j]-x);
//       }
//       repi(j, 1, n) {
//         if(a[j-1] > a[j]) {
//           print(-1);
//           return;
//         }
//       }
//       print(x);
//       return;
//     }
//   }
//   if(!dec) {
//     print(0);
//   }
//   if(dec && !inc) {
//     print(a[0]);
//   }
//   dec = false;
//   inc = false;
//   repi(i, 1, n) {
//     if(a[i-1] > a[i]) {
//       dec = true;
//     }
//     if(a[i-1] < a[i]) {
//       inc = true;
//     }
//     if(inc && a[i-1] > a[i]) {
//       ll x = (a[i]+a[i-1]+1)/2;
//       rep(j, n) {
//         a[j] = llabs(a[j]-x);
//       }
//       repi(j, 1, n) {
//         if(a[j-1] > a[j]) {
//           print(-1);
//           return;
//         }
//       }
//       print(x);
//       return;
//     }
//   }
// }

void solve() {
  ll n; cin >> n;
  v a(n); rep(i, n) cin >> a[i];

  bool dec = false, inc = false;
  ll ub = LL_MAX_S, lb = -LL_MAX_S;
  repi(i, 1, n) {
    if(a[i-1] < a[i]) {
      inc = true;
      ub = min(ub, (a[i-1]+a[i])/2);
    }
    if(a[i-1] > a[i]) {
      dec = true;
      lb = max(lb, (a[i-1]+a[i]+1)/2);
    }
  }
  if(!dec) {
    print(0);
    return;
  }
  if(dec && !inc) {
    print(a[0]);
    return;
  }
  if(lb <= ub) {
    print(lb);
    return;
  }
  print(-1);
}

int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  ll t = 1; cin >> t;
  rep(i, t) solve();
}
