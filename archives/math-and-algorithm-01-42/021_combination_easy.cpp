// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_s

#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int release(void) {
  long n, r; 
  cin >> n >> r;

  long ncr = 1;
  for(int i=0; i<r; i++) ncr *= (n-i);
  for(int i=0; i<r; i++) ncr /= (i+1);

  cout << ncr << endl;
  return 0;
}

int main(void) {
  // return debug();
  return release();
}