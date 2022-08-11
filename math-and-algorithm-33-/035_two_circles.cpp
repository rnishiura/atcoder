#include <bits/stdc++.h>
#define POW(N) ((N)*(N))
using ll = long long;
using namespace std;

int main(void) {
  ll x1, y1, r1, x2, y2, r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  ll d2 = POW(x1-x2) + POW(y1-y2);
  int ret;
  if(POW(r1+r2) < d2) ret = 5;
  else if(POW(r1+r2) == d2) ret = 4;
  else if(POW(r1-r2) > d2) ret = 1;
  else if(POW(r1-r2) == d2) ret = 2;
  else ret = 3;
  cout << ret << endl;;

}

