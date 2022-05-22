#include <iostream>
#include <map>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  int A[N];
  for(int i=0; i<N; i++) {
    cin >> A[i];
  }

  int B[2001];
  for(int i=0; i<2001; i++) B[i] = false;
  for(int i=0; i<N; i++) {
    B[A[i]] = true;
  }
  int i=0;
  for(; i<2001; i++){ 
    if(B[i] == false) break;
  }

  cout << i << endl;
  return 0;
}