#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(void) {
  ll N;
  cin >> N;

  double p = 0;
  for(ll i=1; i<21; i++) {
    p += (double)i / N * pow(1-1/N, i-1);
  } 
  cout << p << endl;
}
