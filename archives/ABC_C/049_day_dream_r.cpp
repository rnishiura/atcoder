#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string token[] = {"dream","dreamer","erase","eraser"};

int main(void) {
  int i;
  ll pos;
  string S;
  cin >> S;

  while(S.length()) {
    for(i=0; i<4; i++) {
      pos = S.length() - token[i].length();
      if(pos < 0) continue;
      if(S.substr(pos) == token[i]) {
        S = S.substr(0, pos);
        break;
      }
    }
    if(i==4) break;
  } 
  if (!S.length()) 
    cout << "YES" << endl;
  else 
    cout <<  "NO" << endl;
}

