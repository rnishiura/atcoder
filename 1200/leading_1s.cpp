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
#define MOD 1000000000000000000
#define LL_MAX  (1LL << 62)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl '\n'
#define printnl(z)      cout << (z) << ' '
#define println()       cout << endl
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

ll power(ll n, ll m) {
  ll s=1;
  while(m) {
    s = (s * (m % 2 ? n : 1)) % MOD;
    n = (n*n) % MOD;
    m >>= 1;
  }
  return s;
}


void solve() {
  ll n; cin >> n;
  ll ans = 0;

  ll head = 0;
  repi(i, 1, 16) {
    head = 10*head+1;
    // head = power(10, i-1);

    // head only
    // case 111...1
    if(head <= n) {
      // print(head);
      ans += i;
    }

    // head and tail
    // case 111...1jXX...X
    // where X, j is 0...9 except j =/= 1
    // and len(XX...X) >= 0
    rep(j, 10) {
      if(j == 1) continue;
      ll base = 10*head+j;
      rep(k, 16-i) {
        // print2(base, base+power(10, k));
        ll ofs=power(10, k);
        if(base <= n && n < base+ofs) {
          // range but <= n
          // print2(base, n);
          ans += i*(n-base+1);
        } else if(base+ofs <= n) {
          // whole range
          // print2(base, base+ofs-1);
          ans += i*ofs;
        }
        base = 10*base;
      }
    }
  }
  print(ans);
}

int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  ll t = 1; // cin >> t;
  rep(i, t) solve();
}
