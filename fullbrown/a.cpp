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

bool xor_cmb(ll n, ll r) {
  r = min(r, n-r);
  if(n == 0 || r == 0) return 1;
  ll m = 1;
  while(n >= m*2) {
    m *= 2;
  }
  n = n-m;
  if(n >= r) {
    return xor_cmb(n, r);
  } else {
    return 0;
  }
}

void solve() {
  ll n, k; cin >> n >> k;
  ll m = n-1, r = k-1;
  ll ans;
  // n even
  if(n%2 == 0) {
    // k odd
    if(k%2 == 1) {
      if(xor_cmb(m/2, r/2)) ans = k+1;
      else ans = k;
    } 
    // k even
    else {
      if(xor_cmb(m/2, r/2)) ans = k-1;
      else ans = k;
    }
  } 
  // n odd
  else {
    // k == 1
    if(k == 1) {
      ans = 2;
    }
    // k == n
    else if(k == n) {
      ans = n-2;
    }
    // k odd
    else if(k%2 == 1) {
      if(k >= 3 && xor_cmb((m-1)/2, r/2-1)) ans = k-2;
      else if(xor_cmb((m-1)/2, r)/2) ans = k+1;
      else ans = k;
    } 
    // k even
    else {
      if(xor_cmb((m-1)/2, r/2)) {
        if(k < n-1 && xor_cmb((m-1)/2, (r+1)/2)) {
          ans = k+2;
        } else {
          ans = k+1;
        }
      }
      else ans = k;
    }
  }
  print(ans);
}

int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  // ll t = 1; cin >> t;
  // rep(i, t) solve();

  ll n = 512;
  rep(i, n) {
    rep(j, n-i) { cout << " "; }
    rep(j, i+1) {
      cout << (xor_cmb(i, j) ? "AA" : "  ");
    }
    print("");
  }
}
