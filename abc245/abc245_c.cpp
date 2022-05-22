#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
  int N, K;
  cin >> N >> K;

  int A[N], B[N];
  for(int i=0; i<N; i++) cin >> A[i];
  for(int i=0; i<N; i++) cin >> B[i];

  bool upper=true, lower=true;

  for(int i=1; i<N; i++) {
    bool prev_upper = upper;
    bool prev_lower = lower;
    if(
      (prev_upper && fabs(A[i-1] - A[i]) <= K) || 
      (prev_lower && fabs(B[i-1] - A[i]) <= K)
      ) upper = true;
    else upper = false;
    if(
      (prev_upper && fabs(A[i-1] - B[i]) <= K) || 
      (prev_lower && fabs(B[i-1] - B[i]) <= K)
      ) lower = true;
    else lower = false;
    if(!upper && ! lower) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}