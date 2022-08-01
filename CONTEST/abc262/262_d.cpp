#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define MOD 998244353
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n); i > 0; i--)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rrepi(i, a, b) for (int i = (int)(a); i > (int)(b); i--)

// 考える整数の最大値
const int MAX = 1000;

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

ll mul(ll a, ll b) {
  return ((a%MOD) * (b%MOD)) % MOD;
}

int main(void) {
  init();
  ll N;
  cin >> N;

  ll T[N];
  for(ll i=0; i<N; i++) {
    cin >> T[i];
  }

  ll cnt = N;
  ll C[N];
  for(ll i=2; i<=N; i++) {
    for(ll j=0; j<N; j++) C[j] = 0;
    for(ll j=0; j<N; j++) C[T[j]%i]++;
    for(ll j=0; j<i; j++) {
      if (C[j] >= i) {
        cnt += cmb(C[j], i);
        cnt %= MOD;
      }
      ll P[i];
      for(ll k=0; k<i; k++) P[k] = k;
      do {

      } next_permutation(P, P+i);
      // for(ll k=j+1; k<i; k++) {
      //   for(ll m=1; m<i; m++) {
      //     if((m*j+(i-m)*k) % i == 0 && C[j] >= m && C[j] >= (i-m)) {
      //       cnt += mul(cmb(C[j], m), cmb(C[k], i-m));
      //       cnt %= MOD;
      //     } 
      //   }
      // }
    }
  }
  cout << cnt << endl;
}


