#include <bits/stdc++.h>
#define POW(N) ((N)*(N))
using ll = long long;
using namespace std;

int main(void) {
  ll N;
  cin >> N;

  ll T[N];
  for(ll i=0; i<N; i++) {
    cin >> T[i];
  }

  sort(T, T+N);
  // reverse(T, T+N);

  ll max_val = T[0];
  ll max_idx = 0;
  ll val;
  for(ll i=1; i<N; i++) {
    val = min(T[i], T[N-1]-T[i]);
    if(max_val >= val) break;
    max_val = val;
    max_idx = i;
  }

  cout << T[N-1] << " " <<  T[max_idx] << endl;
}


