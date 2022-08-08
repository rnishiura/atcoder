#include <bits/stdc++.h>
#define POW(N) ((N)*(N))
using ll = long long;
using namespace std;
#define MAX 100000

int main(void) {
  ll N;
  cin >> N;

  ll T[N];
  for(ll i=0; i<N; i++) {
    cin >> T[i];
  }

  ll O[MAX+1], NO[MAX+1];
  for(ll i=0; i<=MAX; i++) {
    O[i] = -1;
    NO[i] = -1;
  }
  O[0] = 0;

  for(ll i=0; i<N; i++) {
    for(ll j=0; j<=MAX; j++) {
      if (O[j] >= 0) NO[j] = O[j] + T[i];
      if (j>=T[i] && O[j-T[i]] >= 0) {
        if (O[j] >= 0) NO[j] = min(O[j]+T[i], O[j-T[i]]);
        else NO[j] = O[j-T[i]];
      }
    }
    swap(O, NO);
  }
  ll minT = MAX;
  for(ll i=0; i<=MAX; i++) {
    if (O[i] >= 0) {
      minT = min(minT, max(i, O[i]));
    }
  }
  cout << minT << endl;
}

