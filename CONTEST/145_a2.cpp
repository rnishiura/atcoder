#include <bits/stdc++.h>
#define POW(N) ((N)*(N))
using ll = long long;
using namespace std;


int main(void) {
  ll N;
  cin >> N;
  string S;
  cin >> S;
  if (N==2) {
    if (S=="AA" || S=="BB") cout << "Yes" << endl;
    else cout << "No" << endl;
  } 
  else {
    if (S[0] == 'A' && S[N-1] == 'B') cout << "No" << endl;
    else cout << "Yes" << endl;
  }
}


// B...A Yes
// A...B No
// A...A Yes
// B...B Yes