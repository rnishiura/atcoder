#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(void) {
  ll N, S;
  cin >> N >> S;

  ll A;
  set<int> DP, newDP;
  DP.insert(0);
  for(ll i=0; i<N; i++) {
    cin >> A;
    newDP = DP;
    for(auto itr = DP.begin(); itr != DP.end(); itr++) {
      // cout << *itr << endl;
      if (*itr + A <= S)
      newDP.insert(*itr + A);
    }
    DP = newDP;
    // cout << " " << i << endl;
  }
  if (*DP.rbegin() == S) cout << "Yes" << endl;
  else cout << "No" << endl;
}

