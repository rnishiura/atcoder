#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
  int N;
  cin >> N;

  int tmp;
  long B[100000];
  for(int i=1; i<100000; i++) B[i] = 0;

  for(int i=0; i<N; i++) {
    cin >> tmp;
    B[tmp]++;
  }
  
  long ans=0;
  for(int i=1; i<50000; i++) {
    ans += B[i] * B[100000-i];
  }

  if (B[50000] >= 2) {
    ans += B[50000] * (B[50000]-1) / 2;
  }

  cout << ans << endl;
}

