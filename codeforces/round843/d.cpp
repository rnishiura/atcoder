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
#define map unordered_map

using namespace std;
template<typename goal>             vector<goal>& operator--            (vector<goal> &v){for (auto& i : v) --i;            return  v;}
template<typename goal>             vector<goal>& operator++            (vector<goal> &v){for (auto& i : v) ++i;            return  v;}
template<typename goal>             istream& operator>>(istream& is,  vector<goal> &v){for (auto& i : v) is >> i;        return is;}
template<typename goal>             ostream& operator<<(ostream& os,  vector<goal>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename goal, typename U> pair<goal,U>& operator--           (pair<goal, U> &rfactor){--rfactor.first; --rfactor.second;            return  rfactor;}
template<typename goal, typename U> pair<goal,U>& operator++           (pair<goal, U> &rfactor){++rfactor.first; ++rfactor.second;            return  rfactor;}
template<typename goal, typename U> istream& operator>>(istream& is, pair<goal, U> &rfactor){is >> rfactor.first >> rfactor.second;        return is;}
template<typename goal, typename U> ostream& operator<<(ostream& os, pair<goal, U>  rfactor){os << rfactor.first << ' ' << rfactor.second; return os;}
template<typename goal, typename U> pair<goal,U> operator-(pair<goal,U> a, pair<goal,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename goal, typename U> pair<goal,U> operator+(pair<goal,U> a, pair<goal,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename goal, typename U> void umin(goal& a, U b){if (a > b) a = b;}
template<typename goal, typename U> void umax(goal& a, U b){if (a < b) a = b;}
using ll  = long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vp  = vector<pair<ll, ll>>;
using vvp = vector<vp>;



v factorize(ll m) {
  ll n = m;
  v r; ll c;
  for(ll i=2; i*i<=m; i++) {
    c = 0;
    while(m % i == 0) { m /= i; c++; }
    if(c) {
      r.pb(i);
    }
  }
  if(m > 1){
    r.pb(m);
  }
  return r;
}

void solve(void) {
  ll n; cin >> n;

  v a(n+1);
  repi(i, 1, n+1) { cin >> a[i]; }

  ll begin, goal; cin >> begin >> goal;

  if(begin == goal) {
    print(1);
    print(goal);
    return;
  }
  map<ll, v> factor;

  map<ll, v> rfactor;
  repi(i, 1, n+1) {
    if(!contains(a[i], factor)) factor[a[i]] = factorize(a[i]);
    for(auto fact: factor[a[i]]) {
      rfactor[fact].pb(i);
    }
  }

  v hist(n+1, -1); hist[begin] = 0;
  v fr = {begin};
  bool flg = false;
  while(fr.size()) {
    // print(fr);
    v to;
    for(auto f: fr) {
      // print(f);
      // print(factor[f]);
      for(auto fact: factor[a[f]]) {
        for(auto t: rfactor[fact]) {
          if(t == f) continue;
          if(hist[t] == -1) {
            hist[t] = f;
            to.pb(t);
          }
          if(hist[goal] != -1) {
            flg = true;
            goto finish;
          }
        }
      }
    }
    fr.swap(to);
  }

finish:
  if(!flg) {
    print(-1);
    return;
  }

  v restore;
  ll prev = goal;
  while(prev != 0) {
    restore.pb(prev);
    prev = hist[prev];
  }

  print(restore.size());
  rrep(i, restore.size()) cout << restore[i] << " ";
  cout << endl;
}


int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  ll t = 1; // cin >> goal;
  rep(i, t) solve();
}
