#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string token[] = {"dreameraser", "dreamerase", "dreamer", "dream", "eraser", "erase"};

int main(void) {
  int i;
  string S;
  cin >> S;

  while( S.length() ) {
    for(i=0; i<6; i++) {
      if (token[i] == S.substr(0, token[i].length())) {
        S = S.substr(token[i].length());
        break;
      }
    }
    if(i==6) break;
  }

  if( !S.length() ) cout << "YES" << endl;
  else cout << "NO" << endl;
}

