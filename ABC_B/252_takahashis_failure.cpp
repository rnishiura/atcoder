#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
  int N, K;
  cin >> N >> K;
  int A[N], B[K];

  int max=0;
  for(int i=0; i<N; i++) {
    cin >> A[i];
    if(max < A[i]) max = A[i];
  }

  bool flg = false;
  for(int i=0; i<K; i++) {
    int idx;
    cin >> idx;
    if(A[idx-1] == max) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  
  cout << "No" << endl;
  return 0;
}

