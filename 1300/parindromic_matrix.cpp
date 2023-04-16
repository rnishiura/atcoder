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



void solve() {
  ll h, w; cin >> h >> w;
  vector<string> a(h); rep(i, h) cin >> a[i];

  map<char, ll> cnt;
  rep(i, h) {
    rep(j, w) {
      cnt[a[i][j]]++;
    }
  }
  v cnt2;
  rep(i, 26) {
    ll c = cnt[char(i+'a')];
    if(c%4) cnt2.pb(c%4);
    if(c-c%4) cnt2.pb(c-c%4);
  }
  sort(all(cnt2));

  // print(cnt2);
  bool flg=true;
  if(h%2==0 && w%2==0) {
    ll i=0, n=h*w;
    while(n) {
      if(cnt2[i] >= 4) {
        cnt2[i] -= 4;
        n -= 4;
      } else if(cnt2[i] == 0) {
        i++;
      } else {
        flg=false;
        break;
      }
    }
  }
  else if(h%2 && w%2) {
    if(cnt2[0] != 1) flg=false;
    ll i=1, n=h+w-2;
    while(n) {
      if(cnt2[i] >= 2) {
        cnt2[i] -= 2;
        n -= 2;
      } else if(cnt2[i] == 0) {
        i++;
      } else {
        flg=false;
        break;
      }
    }
    n = h*w-h-w+1;
    while(n) {
      if(cnt2[i] >= 4) {
        cnt2[i] -= 4;
        n -= 4;
      } else if(cnt2[i] == 0) {
        i++;
      } else {
        flg=false;
        break;
      }
    }
  } 
  else {
    ll i=0, n=h%2?w:h;
    while(n) {
      if(cnt2[i] >= 2) {
        cnt2[i] -= 2;
        n -= 2;
      } else if(cnt2[i] == 0) {
        i++;
      } else {
        flg=false;
        break;
      }
    }
    n = h*w-(h%2?w:h);
    while(n) {
      if(cnt2[i] >= 4) {
        cnt2[i] -= 4;
        n -= 4;
      } else if(cnt2[i] == 0) {
        i++;
      } else {
        flg=false;
        break;
      }
    }
  }

  if(flg) {
    print("Yes");
  } else {
    print("No");
  }
}

int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  ll t = 1; // cin >> t;
  rep(i, t) solve();
}
