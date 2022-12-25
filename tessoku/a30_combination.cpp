#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define MOD 1000000007
#define LL_MAX_S  (1LL<<62)
#define DBL_MAX_S ((double)LL_MAX_S)
#define rep(x, n)      for(ll x=0; x<n; x++)
#define repi(x, a, b)  for(ll x=a; x<b; x++)
#define rrep(x, n)     for(ll x=n-1; x>=0; x--)
#define rrepi(x, a, b) for(ll x=b-1; x>=a; x--)
#define square(z) ((z)*(z))
#define contains(x, s) (s.find(x) != s.end())
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define unordered_multiset multiset
#define unordered_set set
#define unordered_map map
#define mnl(N, i)  ((N+i)/i) 
#define mnle(N, i) ((N+i-1)/i) 
#define mnse(N, i) ((N)/i) 
#define mns(N, i)  ((N-1)/i) 
#define endl '\n'
#define print(z)        cout << (z) << endl
#define print2(y, z)    cout << (y) << ' '; print(z)
#define print3(x, y, z) cout << (x) << ' '; print2(y, z)
using namespace std;
using ll  = long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vp  = vector<pair<ll, ll>>;
using vvp = vector<vp>;

// 考える整数の最大値
const int MAX = 100001;

// メモを保管する場所
ll fact[MAX], inv_fact[MAX], inv[MAX];

// メモを計算する
void init() {
    // 初期値設定と1はじまりインデックスに直す
    fact[0] = 1;
    fact[1] = 1;
    inv[0] = 1;
    inv[1] = 1;
    inv_fact[0] = 1;
    inv_fact[1] = 1;
    // メモの計算
    repi(i, 2, MAX){
        // 階乗
        fact[i] = fact[i - 1] * i % MOD;
        // 逆元
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        // 逆元の階乗
        inv_fact[i] = inv_fact[i - 1] * inv[i] % MOD;
    }
}

// 二項係数の実体
ll cmb(int n, int k) {
    ll x = fact[n]; // n!の計算
    ll y = inv_fact[n-k]; // (n-k)!の計算
    ll z = inv_fact[k]; // k!の計算
    if (n < k) return 0; // 例外処理
    if (n < 0 || k < 0) return 0; // 例外処理
    return x * ((y * z) % MOD) % MOD; //二項係数の計算
}

ll m(ll a, ll b) {
  return ((a%MOD) * (b%MOD)) % MOD;
}

int main(void) {
  init();

  ll n, r; cin >> n >> r;
  print(cmb(n, r));
}
