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


void solve(void) {
  ll n, m;
  cin >> n >> m;

  vector<set<ll>> gh(n+1), hh(n+1); ll u0, u1;
  set<ll> su0, su1;
  repi(i, 1, n+1) {
    su0.insert(i);
    su1.insert(i);
  }
  rep(i, m) { 
    cin >> u0 >> u1;
    gh[u0].insert(u1);
    gh[u1].insert(u1);
    su0.erase(u0);
    su1.erase(u1);
  }
  vv g(n+1), h(n+1);
  repi(i, 1, n+1) {
    for(auto e: gh[i]) {
      g[i].pb(e);
    }
  }
  // for(auto e: su1) print(e);
  if(su0.size() != 1 || su1.size() != 1) {
    print("No");
    return;
  }
  ll r = *su1.begin();

  vp hist(n+1, mp(-1, -1)); hist[r] = mp(-1, 0);
  v fr = {r};
  while(fr.size()) {
    v to;
    for(auto f: fr) {
      for(auto t: g[f]) {
        if(hist[t].se == -1 || hist[f].se+1 > hist[t].se) {
          hist[t] = mp(f, hist[f].se+1);
          to.pb(t);
        }
      }
    }
    fr.swap(to);
  }
  ll prev = *su0.begin();
  if(hist[prev].se != n-1) {
    print("No");
    return;
  }
  v restore;
  while(prev != -1) {
    restore.pb(prev);
    prev = hist[prev].fi;
  }
  v ra(n+1, 0);
  print("Yes");
  repi(i, 1, n+1) {
    ra[restore[n-i]] = i;
  }
  repi(i, 1, n+1) {
    cout << ra[i] << " ";
  }
  print("");
  // return;
  // rrep(i, restore.size()) cout << restore[i] << " ";
  // cout << endl;
}

// void solve() {
//   ll n, m; cin >> n >> m;

//   vector<set<ll>> g(n+1); ll u0, u1;
//   set<ll> su1;
//   repi(i, 1, n+1) {
//     su1.insert(i);
//   }
//   rep(i, m) { 
//     cin >> u0 >> u1;
//     g[u0].insert(u1);
//     su1.erase(u1);
//   }
//   // for(auto e: su1) print(e);
//   if(su1.size() != 1) {
//     print("No");
//     return;
//   }
//   ll r = *su1.begin();
//   v d(n+1, -1); d[r] = 0;
//   ll fr = r;
//   ll cnt = 1;
//   v h = {-1, r};
//   while(cnt < n && cnt <= 200000) {
//     if(g[fr].size() != 1) {
//       break;
//     }
//     d[r]
//     fr = *g[fr].begin();
//     h.pb(fr);
//     cnt++;
//   }
//   v ra(n+1, 0);
//   if(cnt == n) {
//     print("Yes");
//     repi(i, 1, n+1) {
//       ra[h[i]] = i;
//     }
//     repi(i, 1, n+1) {
//       cout << ra[i] << " ";
//     }
//     print("");
//     return;
//   }
//   print("No");
// }

int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  ll t = 1; // cin >> t;
  rep(i, t) solve();
}
