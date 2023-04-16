/*
Author: rnishiura
Problem: 
Date: 23-02-
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

// 私のコード、可読性低すぎ・・・？

void solve() {
  ll n, k; cin >> n >> k;
  string s; cin >> s;

  ll cx = 0;
  rep(i, n) { if(s[i] == 'X') cx++; }

  if(cx == n) {
    print(k-1);
    return;
  }
  if(cx == 0) {
    print(n-k-1);
    return;
  }
  if(cx >= k) {
    ll lx=0, rx=n-1;
    v mx = {};
    ll i=0;
    while(i<n) {
      if(s[i] == 'Y') {
        lx = i;
        break;
      }
      i++;
    }
    // print(s);
    i=n-1;
    while(i>=0) {
      if(s[i] == 'Y') {
        rx = i;
        // print2(i, rx);
        // print("HO");
        break;
      }
      i--;
    }
    // print2(lx, rx);
    ll px=lx;
    repi(i, lx+1, rx+1) {
      if(s[i] == 'Y') {
        if(i-px-1>0) mx.pb(i-px-1);
        px = i;
      }
    }
    sort(all(mx));
    // print(mx);
    ll ans = 0;
    rep(i, n-1) {
      if(s[i] == 'Y' && s[i+1] == 'Y') ans++;
    }
    i = 0;
    while(k > 0 && i<mx.size()) {
      // print(ans);
      if(mx[i] <= k) {
        k -= mx[i];
        ans += mx[i]+1;
      } else {
        ans += k;
        k = 0;
      }
      i++;
    }
    if(k > 0) {
      ans += k;
      k = 0;
    }
    print(ans);
    return;
  }
  if(cx < k) {
    ll ans = n-1;
    k = k-cx;
    ll lx=0, rx=n-1;
    v mx = {};
    ll i=0;
    while(i<n) {
      if(s[i] == 'X') {
        lx = i;
        break;
      }
      i++;
    }
    i=n-1;
    while(i>=0) {
      if(s[i] == 'X') {
        rx = i;
        break;
      }
      i--;
    }
    ll px=lx;
    repi(i, lx+1, rx+1) {
      if(s[i] == 'X') {
        if(i-px-1>0) mx.pb(i-px-1);
        px = i;
      }
    }
    sort(mx.rbegin(), mx.rend());
    print(mx);
    // print2(lx, rx);
    i = 0;
    // print2(ans, k);
    ans -= min(k, lx+n-rx-1);
    k -= min(k, lx+n-rx-1);
    // print2(ans, k);
    while(k > 0) {
      // print2(k, ans);
      ans--;
      ans -= min(k, mx[i]);
      k -= min(k, mx[i]);
      i++;
    }
    print(ans);
    return;
  }
}

int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  ll t = 1; // cin >> t;
  rep(i, t) solve();
}
