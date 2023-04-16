/*
Problem: https://atcoder.jp/contests/abc222/tasks/abc222_d
Author: rnishiura
Date: 23-02-07
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

vv memo;
ll n;
v a, b;

// ll dfs(ll pos, ll c) {
//   if(pos == n) {
//     return 1;
//   }
//   ll ans = 0, r;
//   rrepi(i, max(a[pos], c), b[pos]+1) {
//     if(memo[pos+1][i] != -1) {
//       ans += memo[pos+1][i];
//       ans %= MOD;
//     } else {
//       r = dfs(pos+1, i) % MOD;
//       ans += r;
//       ans %= MOD;
//       memo[pos+1][i] = r;
//     }
//   }
//   return ans;
// }

void solve() {
  cin >> n;
  a = v(n); rep(i, n) { cin >> a[i]; }
  b = v(n); rep(i, n) { cin >> b[i]; }
  memo = vv(n+1, v(3001, 1));
  // print(dfs(0, -1));

  rrep(i, n-1) {
    ll s = 0;
    rrepi(j, a[i], b[i+1]+1) {
      if(a[i+1] <= j && j <= b[i+1]) {
        s += memo[i+1][j];
        s %= MOD;
      }
      if(a[i] <= j && j <= b[i]) {
        memo[i][j] = s;
      }
    }
  }

  ll ans = 0;
  repi(i, a[0], b[0]+1) {
    ans += memo[0][i];
    ans %= MOD;
  }
  print(ans);
  // for(auto val: memo) {
  //   print(val);
  // }

  // print()
}

int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  ll t = 1; // cin >> t;
  rep(i, t) solve();
}
