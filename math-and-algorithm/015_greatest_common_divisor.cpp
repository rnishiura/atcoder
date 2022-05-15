#include <iostream>
#include <cmath>
using namespace std;

long gcd(long a, long b) {
  long ret = 0;
  long tmp = 0;
  if (a > b) { a=a+b; b=a-b; a=a-b; }
  for(long i=1; i<=sqrt(a); i++) {
    if(a%i == 0) {
      if(b%i     == 0) ret = max(ret, i);
      if(b%(a/i) == 0) ret = max(ret, a/i);
    }
  }
  return ret;
}

int main() {
  long a, b;
  cin >> a >> b;
  cout << gcd(a, b) << endl;

  return 0;
}
