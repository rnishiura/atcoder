#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int main(int argc, char *argv[]) {
  ll B = 1, W = 1;

  enum MODE {BW, WB, AB, AW};
  MODE M = BW;

  string s;
  cin >> s;

  for(ll i=0; i < s.length(); i++) {
    if(M==BW && s[i]=='R' || M==WB && s[i]=='L') {
      if(i%2 == 0) {
        B += W+1;
        W = 0;
        M = AB;
      } else W++;
    } else if (M==BW || M==WB) {
      if(i%2 == 1) {
        W += B+1;
        B = 0;
        M = AW;
      } else B++;
    }
    else if(M==AB){
      if(i%2 == 0) B++;
      else {
        W++;
        if (s[i] == 'R') M = BW;
        else M = WB;
      }
    }
    else if(M==AW) {
      if(i%2 == 1) W++;
      else {
        B++;
        if (s[i] == 'R') M = WB;
        else M = BW;
      }
    }
  }

  cout << B << " " << W << endl;
  return 0;
}
