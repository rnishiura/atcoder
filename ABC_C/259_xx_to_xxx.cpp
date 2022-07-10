#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(void) {
  string S, T;
  ll i, j;
  char c, d;
  cin >> S >> T;

  while(S.length()) {
    c = S[0];
    d = T[0];
    if (c != d) break;
    for(i=1; i<S.length(); i++) {
      if(S[i] != c) break;
    }
    for(j=1; j<T.length(); j++) {
      if(T[j] != d) break;
    }
    if(i == 1 && j > 1) break;
    if(i > j) break;
    S = S.substr(i);
    T = T.substr(j);
  }
  if( !S.length() && !T.length() ) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

