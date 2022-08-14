#include <iostream>
#include <cmath>
using namespace std;

// 素数判定
bool isPrimeNumber(int n) {
  bool flg = true;

  for (long i=sqrt(n); i>1; i--) {
    if (n % i == 0) flg = false;
  }
  return flg;
}

int main() {
    long n;
    cin >> n;

    for (int i=2; i<=n; i++) {
      if (isPrimeNumber(i)) {
        cout << i << " ";
      }
    }

    cout << endl;

    return 0;
}
