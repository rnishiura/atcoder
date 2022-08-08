#include <bits/stdc++.h>
#define MOD 998244353
#define POW(N) ((N)*(N))
using ll = long long;
using namespace std;

int main(void) {
  ll N;
  cin >> N;

  ll A[N];
  for(ll i=0; i<N; i++) cin >> A[i];

  ll cnt = 0;

  // 1. iteration
  for(ll i=1; i<=N; i++) {
    // cout << i << endl;
    ll DP[i+1][i], newDP[i+1][i];
    for(ll k=0; k<=i; k++) {
      for(ll l=0; l<i; l++) {
        DP[k][l] = 0;
        newDP[k][l] = 0;
      }
    }
    // 2. modulation
    for(ll j=0; j<N; j++) {
      ll B = A[j] % i;
      // 3. summation 
      for(ll l=0; l<i; l++) newDP[1][l] = DP[1][l] % MOD;
      newDP[1][B]++;
      for(ll k=2; k<=i; k++) {
        // 4. rotation
        for(ll l=0; l<i; l++) newDP[k][l] = DP[k][l] + DP[k-1][(l+i-B)%i] % MOD;
      }
      for(ll k=0; k<=i; k++) {
        for(ll l=0; l<i; l++) {
          DP[k][l] = newDP[k][l];
        }
      }
      // for(ll k=0; k<=i; k++) {
      //   for(ll j=0; j<i; j++) cout << DP[k][j];
      //   cout << " ";
      //   }
      //   cout << endl;
    }

    cnt = (cnt + DP[i][0]) % MOD;
  }
  cout << cnt << endl;
}


