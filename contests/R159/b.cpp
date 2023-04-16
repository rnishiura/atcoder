/*
Author: rnishiura
Problem: 
Date: 23-04-
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

ll gcd(ll a, ll b) {
  if (a < b) swap(a, b);
  if (a%b==0) return b;
  else return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
  ll g = gcd(a, b);
  return g * (a/g) * (b/g);
}


void solve() {
  ll A, B; cin >> A >> B;

  ll a = A, b = B;

  ll cnt=0, g;
  // while(a && b) {
  //   g = gcd(a, b);
  //   a = a/g-1;
  //   b = b/g-1;
  //   print(g);
  //   cnt++;
  // }
  if(a <= 0 || b <= 0) {
    print(0);
    return;
  }
  if(A == B) {
    print(1);
    return;
  }
  g = gcd(a, b);
  if(g > 1) {
    a = a/g-1;
    b = b/g-1;
    cnt++;
  }
  while(a && b) {
    ll r=inf, x=1;
    ll mm = max(a, b) - min(a, b);
    if(mm == 0) {
      break;
    }
    for(g = 1; g*g <= mm; g++) {
      if(mm%g != 0) continue;
      if(g != 1 && a%g == b%g && a%g <= r) {
        x = min(g, x);
        x = g;
        r = a%g;
      }
      g = mm/g;
      if(a%g == b%g && a%g <= r) {
        x = min(g, x);
        x = g;
        r = a%g;
      }
      g = mm/g;
    }
    if(r == inf || x == 1) { break;}
    g = x;
    cnt += a%g+1;
    a = a/g-1;
    b = b/g-1;
  }
  print(cnt+min(a,b));
}

int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  ll t = 1; // cin >> t;
  rep(i, t) solve();
}
