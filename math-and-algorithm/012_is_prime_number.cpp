#include <iostream>
#include <cmath>
using namespace std;

// 素数判定

int main() {
    long n;
    cin >> n;

    bool flg = true;

    for (long i=sqrt(n); i>1; i--) {
      if (n % i == 0) flg = false;
    }

    if (flg) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
    return 0;
}
