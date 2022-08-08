#include <bits/stdc++.h>
#define POW(N) ((N)*(N))
using ll = long long;
using namespace std;

int main(void) {
  ll N, M, K;
  cin >> N >> M >> K;

  for(ll i=0; i<=N; i++) {
    for(ll j=0; j<=M; j++) {
      if(i*(M-j)+j*(N-i) == K) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}


