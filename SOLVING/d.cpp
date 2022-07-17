#include <bits/stdc++.h>
#define POW(N) (N*N)
using ll = long long;
using namespace std;

int main(void) {
  ll N;
  cin >> N;

  ll tmp;
  ll A[200], _A[200];
  for(ll i=0; i<200; i++) {
    A[i] = 0;
  }
  A[0] = 1;

  for(ll i=0; i<N; i++) {
    for(ll i=0; i<200; i++) {
      _A[i] = A[i];
    }
    cin >> tmp;
    for(ll j=0; j<200; j++) {
      if(_A[j]) A[(j+tmp)%200]++;
    }
    cout << endl;
    for(ll j=0; j<200; j++) {
      cout << A[j] << " ";
    }
  }
  A[0]--;

  cout << endl;
  ll i=0;
  for(; i<200; i++) if(A[i] > 1) break;
  cout << i << endl;
  if (i != 200) cout << "Yes" << endl;
  else cout << "No" << endl;

}

