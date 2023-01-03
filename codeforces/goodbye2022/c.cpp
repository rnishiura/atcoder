/*
Problem: https://codeforces.com/contest/1770/problem/C
Author: rnishiura
Date: 221231
Description:
k*gcd(ai, aj) 
= l*gcd(ai+x, aj+x) 
= max(ai, aj) - min(ai, aj) 
= p1p2p3...pm
Only when pi divides min(ai, aj) pi divides gcd(ai, aj)
So if min(ai, aj) % pi ranges 0...pi-1, 
min(ai+x, aj+x) % pi as well ranges 0...pi-1 
Where any x cannot make every min(ai+x, aj+x) % pi to non 0
Then such x that pi divides gcd(ai+x, aj+x) for every i, j doesn't exist
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

void prime(v &a, ll N) {
  vector<bool> tmp(N+1, true);
  ll end = sqrt(N+1)+1;
  for(ll i=2; i<=end; i++) {
    while(!tmp[i] && i<=end) i++;
    for(ll j=2; i*j<=N; j++) tmp[i*j] = false;
  }
  a.empty();
  for(ll i=2; i<=N; i++) if(tmp[i]) a.push_back(i);
}

void solve() {
  ll n; cin >> n;
  v a(n); rep(i, n) {
    cin >> a[i];
  }

  v p; prime(p, 100);
  
  map<ll, set<ll>> q;
  rep(i, n) {
    repi(j, i+1, n) {
      ll l = max(a[i], a[j]);
      ll s = min(a[i], a[j]);
      if(l == s) {
        print("NO");
        return;
      }
      for(ll val: p) {
        if((l-s) % val == 0) {
          q[val].insert(s%val);
        }
      }
    }
  }
  for(ll val: p) {
    if(q[val].size() == val) {
      print("NO");
      return;
    }
  }
  print("YES");
}

int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  ll t = 1; cin >> t;
  rep(i, t) solve();
}
