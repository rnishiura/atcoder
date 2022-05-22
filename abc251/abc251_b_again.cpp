#include <iostream>
using namespace std;

int main(void) {  
  int N, W;
  cin >> N >> W;
  
  int A[N];
  for(int i=0; i<N; i++) {
    cin >> A[i];
  }

  bool n[W+1];
  for(int i=0; i<=W; i++) n[i] = false; 

  int idx;
  for(int i=0; i<N; i++) {
    idx = A[i];
    if (idx <= W) n[idx] = true;

    for(int j=i+1; j<N; j++) {
      idx = A[i] + A[j];
      if (idx <= W) n[idx] = true;

      for(int k=j+1; k<N; k++) {
        idx = A[i] + A[j] + A[k];
        if (idx <= W) n[idx] = true;
      }
    }
  }

  int cnt = 0;
  for(int i=1; i<=W; i++) {
    if (n[i]) cnt++;
  }

  cout << cnt << endl;
}