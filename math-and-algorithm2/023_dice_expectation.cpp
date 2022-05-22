#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main(void) {
  int N;
  double B_sum=0, R_sum=0;
  cin >> N;
  
  int tmp;
  for(int i=0; i<N; i++) {
    cin >> tmp;
    B_sum += tmp;
  }
  for(int i=0; i<N; i++) {
    cin >> tmp;
    R_sum += tmp;
  }
  printf("%lf\n", (B_sum + R_sum) / N);
  // cout << (B_sum + R_sum) / N << endl;
  return 0;
}

