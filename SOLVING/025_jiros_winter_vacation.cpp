#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(void) {
  ll N;
  cin >> N;

  ll E=0;
  ll t;
  for(ll i=0; i<N; i++) {
    cin >> t;
    E += t;
  }  
  for(ll i=0; i<N; i++) {
    cin >> t;
    E += 2*t;
  }
  cout << (double)E / 3 << endl;
}

