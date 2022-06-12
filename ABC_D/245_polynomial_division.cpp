#include <iostream>
#include <map>
#include <utility>
using namespace std;

int main(void) {
  int N, M;
  cin >> N >> M;
  int A[N+1], B[M+1], C[N+M+1];
  for(int i=0; i<=N  ; i++) cin >> A[i];
  for(int i=0; i<=N+M; i++) cin >> C[i];

  int ofs = 0;
  for(; A[ofs] == 0; ofs++);

  for (int i=0; i<=M; i++) {
    B[i] = C[i+ofs];
    for(int j=1; j<=i; j++) {
      if (j+ofs == N+1) break;
      B[i] -= A[j+ofs] * B[i-j];
    }
    B[i] /= A[0+ofs];
  }

  for(int i=0; i<=M; i++) cout << B[i] << " ";
  cout << endl;
}