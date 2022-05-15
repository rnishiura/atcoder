#include <iostream>
#include <cmath>
using namespace std;

// 素因数分解
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


  // 平方根以下の探索; そしてその対
  for (long i=sqrt(n); i>1; i--) {
    if (n%i == 0) {
      if (isPrimeNumber(i)) 
        cout << i << endl;
      if (isPrimeNumber(n/i)) 
        cout << n/i << endl;
    }
  }

  return 0;
}
