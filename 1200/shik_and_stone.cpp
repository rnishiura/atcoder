/*
Problem: https://atcoder.jp/contests/agc007/tasks/agc007_a
Author: rnishiura
Date: 23-01-06
Description:
Move down or move right
And track the pass
When goaled, check if all # is passed
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
#define divl(n, move)  ((n+move)/(move)) 
#define divle(n, move) ((n+move-1)/(move)) 
#define divse(n, move) ((n)/(move)) 
#define divs(n, move)  ((n-1)/(move)) 
#define MOD 998244353
#define LL_MAX  (1LL << 62)
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

ll h, w; 
vv memo;
vector<string> a; 

bool recur(ll y, ll x, vv move) {
  move[y][x] = 1;
  if(y == h-1 && x == w-1) {
    rep(i, h) {
      rep(j, w) {
        if(a[i][j] == '#' && move[i][j] == 0) {
          return false;
        }
      }
    }
    return true;
  }
  // if(memo[y][x] != -1) return memo[y][x];
  bool r=false;
  if(y+1 < h && a[y+1][x] == '#') r = r || recur(y+1, x, move);
  if(x+1 < w && a[y][x+1] == '#') r = r || recur(y, x+1, move);
  // memo[y][x] = r;
  return r;
}

void solve() {
  cin >> h >> w;
  a = vector<string>(h);
  rep(i, h) {
    cin >> a[i];
  }
  vv move(h, v(w, 0));
  memo = vv(h, v(w, -1));
  print(recur(0, 0, move) ? "Possible" : "Impossible");
}

int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  ll t = 1; // cin >> t;
  rep(i, t) solve();
}
