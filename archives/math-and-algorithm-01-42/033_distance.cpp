#include <bits/stdc++.h>
#define POW(N) ((N)*(N))
using ll = long long;
using namespace std;

int main(void) {
  double ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  double a2 = POW(bx-cx) + POW(by-cy);
  double b2 = POW(cx-ax) + POW(cy-ay);
  double c2 = POW(ax-bx) + POW(ay-by);
  double cosB = (a2+c2-b2) / 2 / sqrt(a2*c2);
  double cosC = (a2+b2-c2) / 2 / sqrt(a2*b2);
  double bsinC = sqrt(b2 - POW(a2+b2-c2) / 4 / a2);
  if (cosB < 0) {
    printf("%lf\n", sqrt(c2));
  }
  else if (cosC < 0) {
    printf("%lf\n", sqrt(b2));
  } 
  else {
    printf("%lf\n", bsinC);
  }
}

