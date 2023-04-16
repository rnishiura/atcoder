/*
Problem: 
Author: rnishiura
Date: 23-
Description:
*/

#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(x, n)      for(ll x=0; x<n; x++)
#define repi(x, a, b)  for(ll x=a; x<b; x++)
#define rrep(x, n)     for(ll x=n-1; x>=0; x--)
#define rrepi(x, a, b) for(ll x=b-1; x>=a; x--)
#define square(z) ((z)*(z))
#define contains(x, a) ((a).find(x) != (a).end())
#define all(a) (a).begin(), (a).end()
#define sum(a)  (accumulate(all(a), 0LL))
#define mini(a) (min_element(all(a)) - (a).begin())
#define maxi(a) (max_element(all(a)) - (a).begin())
#define mine(a) (*min_element(all(a)))
#define maxe(a) (*max_element(all(a)))
#define lowb(x, a) (lower_bound(all(a), (x)) - (a).begin())
#define uppb(x, a) (upper_bound(all(a), (x)) - (a).begin())
#define divl(n, m)  ((n+m)/(m)) 
#define divle(n, m) ((n+m-1)/(m)) 
#define divse(n, m) ((n)/(m)) 
#define divs(n, m)  ((n-1)/(m)) 
#define MOD 998244353
#define inf (1LL << 61)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl '\n'
#define print(z)        cout << (z) << endl
#define print2(y, z)    cout << (y) << ' '; print(z)
#define print3(x, y, z) cout << (x) << ' '; print2(y, z)
#define unordered_multiset multiset

using namespace std;
template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}
using ll  = long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vp  = vector<pair<ll, ll>>;
using vvp = vector<vp>;

ll n, m; 
v c;
vv g;
vv memo;
ll max_k;
ll cnt;

void dfs(ll tpos, ll tppos, ll apos, ll appos, ll k) {
  cnt++;
  if(memo[tpos][apos] == -1 || k < memo[tpos][apos]) {
    memo[tpos][apos] = k;
  } else {
    return;
  }
  // if(tpos == n && apos == 1) {
  //   // print2(tppos, appos);
  //   // print(memo[tppos][appos]);
  //   // max_k = min(max_k, k);
  //   // return k;
  // }
  // if(k > max_k) {
  //   return;
  // }
  for(auto tto: g[tpos]) {
    for(auto ato: g[apos]) {
      // if(tto == tppos && ato == appos) continue;
      if(c[tto] != c[ato]) {
        dfs(tto, tpos, ato, apos, k+1);
      }
    }
  }
}

void solve() {
  cin >> n >> m;
  c = v(n+1);
  repi(i, 1, n+1) cin >> c[i];

  g = vv(n+1); 
  memo = vv(n+1, v(n+1, -1));
  // memo[0][0] = 1;
  // max_k = 10000;
  ll u0, u1;
  rep(i, m) { cin >> u0 >> u1; g[u0].pb(u1); g[u1].pb(u0); }

  cnt = 0;
  dfs(1, -1, n, -1, 0);
  // print(r != inf ? r : -1);
  print(memo[n][1]);

  // print(cnt);
  // for(auto a: memo) {
  //   print(a);
  // }
}

int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  ll t = 1; cin >> t;
  rep(i, t) solve();
}
