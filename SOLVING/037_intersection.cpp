#include <bits/stdc++.h>
#define POW(N) ((N)*(N))
using ll = long long;
using namespace std;

ll line(ll x1, ll x2, ll x3, ll y1, ll y2, ll y3) {
  return (y3-y1)*(x2-x1)-(y2-y1)*(x3-x1);
}

ll dist2(ll x1, ll x2, ll y1, ll y2) {
  return POW(x1-x2) + POW(y1-y2); 
}

int main(void) {
  ll x1, x2, x3, x4, y1, y2, y3, y4;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  ll a, b, c, d;
  a = line(x1, x2, x3, y1, y2, y3);
  b = line(x1, x2, x4, y1, y2, y4);
  c = line(x3, x4, x1, y3, y4, y1);
  d = line(x3, x4, x2, y3, y4, y2);
  if (!a && !b && !c && !d) {
    if ((x3-x2)*(x4-x2)+(y3-x2)*(y4-y2) <= 0 || (x3-x1)*(x4-x1)+(y3-x1)*(y4-y1) <= 0) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else {
    // cout << a << endl << b << endl << c << endl << d << endl;
    bool j = a * b <= 0 && c * d <= 0;
    if(j) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}

