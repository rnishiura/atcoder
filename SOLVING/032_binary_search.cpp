#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(void) {
  ll N, X;
  cin >> N >> X;

  ll tmp;
  set<ll> A;
  for(ll i=0; i<N; i++) {
    cin >> tmp;
    A.insert(tmp);
  }

  if(A.find(X) != A.end()) cout << "Yes" << endl;
  else cout << "No" << endl;
}

