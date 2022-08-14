#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(void) {
  int N;
  cin >> N;
  ll A[N];
  for(ll i=0; i<N; i++) {
    cin >> A[i];
  }
  sort(A, A+N);
  for(ll i=0; i<N; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
}
