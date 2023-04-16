/*
Problem: 
Author: rnishiura
Date: 23-
Description:
* return during input is dangerous
* 
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
#define sesort(a)  sort(all(a), [](auto &x, auto &y) {return x.se < y.se;})
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



void solve() {
  ll n, k; cin >> n;
  vp a(n+1, mp(-1, 0));
  v b(n+1, 0);
  multiset<ll> t;
  repi(i, 1, n+1) {
    t.insert(i);
    t.insert(i);
  }
  repi(i, 1, n+1) {
    cin >> k;
    a[i] = mp(k, i);
    b[k]++;
  }
  repi(i, 1, n+1) {
    if(b[i] > 2) {
      print("NO");
      return;
    }
  }
  repi(i, 1, n+1) {
    t.erase(t.find(a[i].fi));
  }
  v c, d;
  repi(i, 1, n+1) {
    if(b[i] == 2) c.pb(i);
    if(b[i] == 0) d.pb(i);
  }
  sort(all(a));
  sort(all(c));
  sort(all(d));
  // for(auto val: a) {
  //   cout << val.fi << " " << val.se << " ";
  // }
  // print("");
  // for(auto val: c) {
  //   cout << val << " ";
  // }
  // print("");
  // for(auto val: c) {
  //   cout << val << " ";
  // }
  // print("");
  vp p = a;
  ll cnt=0;
  vector<bool> pf(n+1, false);
  repi(i, 1, n+1) {
    if(cnt >= c.size()) break;
    if(a[i].fi == c[cnt]) {
      p[i] = mp(d[cnt], p[i].se);
      pf[i] = true;
      cnt++;
    }
  }
  set<ll> u(t.begin(), t.end());
  auto it=u.begin();
  repi(i, 1, n+1) {
    if(pf[i] == false) {
      p[i] = mp(*it, p[i].se);
      it=next(it);
    }
  }
  repi(i, 1, n+1) {
    if(a[i].fi < p[i].fi) {
      print("NO");
      return;
    }
    if(pf[i]) {
      swap(a[i], p[i]);
    }
  }
  print("YES");
  sesort(a);
  sesort(p);
  // sort(all(a), [](auto &x, auto &y) {return x.se < y.se;});
  // sort(all(p), [](auto &x, auto &y) {return x.se < y.se;});
  repi(i, 1, n+1) {
    cout << a[i].fi << " "; 
  }
  print("");
  repi(i, 1, n+1) {
    cout << p[i].fi << " "; 
  }
  print("");
}

int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  ll t = 1; cin >> t;
  rep(i, t) solve();
}
