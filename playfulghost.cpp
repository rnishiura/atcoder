#include <bits/stdc++.h>

using namespace std;

// int foreach_comb(int i) {
//   int a = [];
// }

int myMap(int a[], int len, void func(int) ) {
  for(int i=0; i<len; i++) {
    func(a[i]);
  }
  return 0;
}

void myFunc(int n) {
  cout << n*n << endl;
}

int main(void) {
  int a[] = {1,2,3};
  myMap(a, 3, &myFunc);
}