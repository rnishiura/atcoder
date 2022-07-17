#include <bits/stdc++.h>
#define POW(N) (N*N)
using ll = long long;
using namespace std;

int main(void) {
  ll N, K;
  cin >> N >> K;
  for(ll i=0; i<K; i++) {
    if (N%200 == 0) {
      N /= 200;
    }
    else {
      N = 1000 * N + 200;
    }
  }
  cout << N << endl;
}

