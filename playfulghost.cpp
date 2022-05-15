#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <utility>
#include <tuple>

using namespace std;

// int foreach_comb(int i) {
//   int a = [];
// }

string i2s(unsigned int i) {
  if(i>256) {
    cout << "too big number" << endl;
    return 0;
  }
  return "" + (unsigned char)(i);
}

int gcd(int a, int b) {
    int ret;

    for (int i=2; i<=min(a, b); i++) {
       if (a % i == 0 && b % i == 0) {
           ret = i;
       }
    }

    return ret;
} 

int main(void) {
  int i, j;
  cin >> i >> j;
  cout << gcd(i, j) << endl;

  return 0;

  pair<int, int> v[5];
  array<int, 2> tmp[] = {{3,2},{1,2},{6,2},{3,1},{1,1}};
  for (int i=0; i<5; i++) {
    v[i] = make_pair(tmp[i][0], tmp[i][1]);
  }
  sort(v, v+5);
  for (int i=0; i<5; i++) {
    cout << v[i].first << v[i].second << endl;
  }
  // std::sort(tmp.begin(), tmp.end(), [](auto& x, auto& y){return x[0] < y[0];});
}