#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool rf(ll S, ll *A, ll N) {
  if (S == 0) return true;
  if (S < 0 || N == 0) return false;
  return rf(S, A+1, N-1) || rf(S-A[0], A+1, N-1);
}

int main(void) {
  ll N, S;
  cin >> N >> S;

  ll A[N];
  for(ll i=0; i<N; i++) cin >> A[i];

  if (rf(S, A, N)) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}

