/*
https://atcoder.jp/contests/arc124/tasks/arc124_b
if a xor c = b then a = b xor c 
therefore in the problem if
a1 xor bx1 = x
a2 xor bx2 = x
.
.
an xor bxn = x
then
bx1 = a1 xor x
bx2 = a2 xor x
.
.
bxn = an xor x
and if {a} can be sorted to equal {b}
then sorted {a} and sorted {b} are equal
therefore in the problem sort {ai xor x} and {bxi}
then check if they are equal 

Generally, to sort {ai} and {bj} to meet the condition ai ~ bxj = c
where ~ is a operator, and if you can rewrite the condition into 
the form ai = f(bxj, c), you can check if sorted {ai} and sorted {f(bxj, c)}
are equal. If not, such that condition cannot be met.
For example, to sort {pi} and {qj} to meet the condition pi xor qxj = r
where pi = r xor qxj then check if sorted {pi} and sorted {r xor qxj} are equal.
221229 rnishiura
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


void solve() {
  ll n, x; cin >> n;
  v a(n), b(n), c(n); 
  rep(i, n) { cin >> a[i]; }
  rep(i, n) { cin >> b[i]; }
  
  sort(all(b));

  set<ll> r;
  rep(i, n) {
    x = a[0]^b[i];
    rep(j, n) {
      c[j] = a[j]^x;
    }
    sort(all(c));
    bool flg=true;
    rep(j, n) {
      if(c[j] != b[j]) {
        flg = false;
        break;
      }
    }
    if(flg) r.insert(x);
  }

  print(r.size());
  for(ll val: r) print(val);
}

int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  ll t = 1; // cin >> t;
  rep(i, t) solve();
}
