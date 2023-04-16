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


ll inv(ll i) {
  if(i==1) return 1;
  return MOD - inv(MOD%i) * (MOD/i) % MOD;
}

void solve() {
  ll N, A, B, P, Q; 
  cin >> N >> A >> B >> P >> Q;

  v adp(N, 0), bdp(N, 0);

  adp[A] = 1;
  bdp[B] = 1;

  ll invPi = inv(P), invQi = inv(Q);
  ll ans = 0;

  ll prevB = 1;

  rep(i, N+10) {
    v nadp(N, 0), nbdp(N, 0);
    ll nca=0, ncb=0, sca=0, scb=0;
    rep(j, N) {
      rep(k, P) {
        sca += adp[j];
        sca %= MOD;
        if(j+k+1 < N) {
          nadp[j+k+1] += adp[j];
          nadp[j+k+1] %= MOD;
        }
        else {
          nca += adp[j];
          nca %= MOD;
        }
      }
      rep(k, Q) {
        scb += bdp[j];
        scb %= MOD;
        if(j+k+1 < N) {
          nbdp[j+k+1] += bdp[j];
          nbdp[j+k+1] %= MOD;
        }
        else {
          ncb += bdp[j];
          ncb %= MOD;
        }
      }
    }

    ans += (nca*invPi%MOD)*prevB%MOD;
    ans %= MOD;

    prevB = (scb-ncb+MOD)%MOD*invQi%MOD;  

    adp = nadp;
    bdp = nbdp;

    invPi = (invPi * inv(P)) % MOD;
    invQi = (invQi * inv(Q)) % MOD;
  }
  print(ans);
}

int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  ll t = 1; // cin >> t;
  rep(i, t) solve();
}
