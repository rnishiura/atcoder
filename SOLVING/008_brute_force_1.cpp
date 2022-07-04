#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(void) {
  int N, S;
  cin >> N >> S;

  if(2*N <= S) {
    cout << N*N << endl;
  }
  else if(N < S) {
    ll tmp = (S/2)*(S/2+1)/2
    cout << (S-N)*(S-N+1)/2 << endl;
  } else {
    cout << S*(S-1)/2 << endl;
  }
}

