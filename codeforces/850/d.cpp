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



void solve() {
  ll m; cin >> m;
  map<ll, set<ll>> a;
  map<ll, map<ll, set<ll>>> b;
  set<ll> c;
  string s;
  v cnt;
  repi(i, 1, m+1) {
    cin >> s;
    cnt = v(4, 0);
    rep(j, 3) {
      switch(s[j]) {
        case 'w': cnt[1]++; break;
        case 'i': cnt[2]++; break;
        case 'n': cnt[3]++; break;
      }
    }
    if(cnt[1] == 1 && cnt[2] == 1 && cnt[3] == 1) c.insert(i);
    repi(j, 1, 4) {
      if(cnt[j] == 3) a[j].insert(i);
    }
    repi(j, 1, 4) {
      if(cnt[j] == 2 && cnt[j%3+1]) {
        b[j][j%3+1].insert(i);
      }
      if(cnt[j] == 2 && cnt[(j+1)%3+1]) {
        b[j][(j+1)%3+1].insert(i);
      }
    }
    // repi(j, 1, 4) {
    //   print(a[j]);
    // }
    // print(cnt);
  }
  // for(ll val: a[1]) print(val);
  // print("");
  vv r;
  // rep(i, 10) {
  while(c.size() < m) {
    rep(i, 3) {
      ll p = (i+1)%3+1, q = (i+2)%3+1;
      while(b[p][i+1].size() && b[q][i+1].size()) {
        auto it1 = b[p][i+1].begin(), it2 = b[q][i+1].begin();
        r.pb({*it1, p, *it2, q});
        c.insert(*it1); c.insert(*it2);
        b[p][i+1].erase(it1);
        b[q][i+1].erase(it2);
      }
    }
    rep(i, 3) {
      ll p = (i+1)%3+1, q = (i+2)%3+1;
      if(b[i+1][p].size() && b[p][q].size()) {
        auto it1 = b[i+1][p].begin(), it2 = b[p][q].begin();
        r.pb({*it1, i+1, *it2, p});
        c.insert(*it1);
        b[p][i+1].insert(*it2);
        b[i+1][p].erase(it1);
        b[p][q].erase(it2);
      }
    }
    rep(i, 3) {
      ll p = (i+1)%3+1, q = (i+2)%3+1;
      if(b[q][p].size() && b[p][i+1].size()) {
        auto it1 = b[q][p].begin(), it2 = b[p][i+1].begin();
        r.pb({*it1, q, *it2, p});
        c.insert(*it2);
        b[p][q].insert(*it1);
        b[q][p].erase(it1);
        b[p][i+1].erase(it2);
      }
    }
    rep(i, 3) {
      ll p = (i+1)%3+1, q = (i+2)%3+1;
      if(b[i+1][p].size() && a[q].size()) {
        auto it1 = b[i+1][p].begin(), it2 = a[q].begin();
        r.pb({*it1, i+1, *it2, q});
        c.insert(*it1);
        b[q][i+1].insert(*it2);
        b[i+1][p].erase(it1);
        a[q].erase(it2);
      }
    }
    rep(i, 3) {
      ll p = (i+1)%3+1, q = (i+2)%3+1;
      if(b[i+1][q].size() && a[p].size()) {
        auto it1 = b[i+1][q].begin(), it2 = a[p].begin();
        r.pb({*it1, i+1, *it2, p});
        c.insert(*it1);
        b[p][i+1].insert(*it2);
        b[i+1][q].erase(it1);
        a[p].erase(it2);
      }
    }
    rep(i, 3) {
      ll p = (i+1)%3+1, q = (i+2)%3+1;
      if(a[i+1].size() && a[p].size()) {
        auto it1 = a[i+1].begin(), it2 = a[p].begin();
        r.pb({*it1, i+1, *it2, p});
        b[p][i+1].insert(*it2);
        b[i+1][p].insert(*it1);
        a[i+1].erase(it1);
        a[p].erase(it2);
      }
    }
  }
  print(r.size());
  vector<char> ch = {'\0', 'w', 'i', 'n'};
  for(v arr: r) {
    cout << arr[0] << " " << ch[arr[1]] << " " << arr[2] << " " << ch[arr[3]] << endl;
  }
}

int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  ll t = 1; cin >> t;
  rep(i, t) solve();
}
