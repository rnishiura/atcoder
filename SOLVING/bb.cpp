#include <bits/stdc++.h>
#define POW(N) (N*N)
#define F(i, a, b) for(ll i=a; i<b; i++)
using ll = long long;
using namespace std;

int main(void) {
  ll N, a, b;
  cin >> N >> a >> b;

  ll A[N];
  ll avr = 0;
  F(i, 0, N) {
    cin >> A[i];
    avr += A[i];
  }
  avr /= N;
  sort(A, A+N);

  ll dl = A[0];
  ll ret;
  for(ll C=dl; C<=avr; C++) {
    // cout << "!" << C << endl;
    ll dc=0, uc=0;
    for(ll j=0; j<N; j++) {
      if(A[j] > C) {
        uc += (A[j]-C) / b;
      } else {
        dc += ceil((double)(C-A[j]) / a);
      }
    }
    // cout << uc << " " << dc << endl;
    if (uc >= dc) {
      ret = C;
    } 
    else break;
  }
  cout << ret << endl;

}