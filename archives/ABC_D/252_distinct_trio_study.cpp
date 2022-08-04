#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
  int N;
  cin >> N;

  int A[N];
  for(int i=0; i<N; i++) cin >> A[i];

  int num=0;
  for(int i=0; i<N; i++)
    for(int j=i+1; j<N; j++)
      for(int k=j+1; k<N; k++)
        if(A[i] != A[j] && A[j] != A[k] && A[k] != A[i]) num++;
  
  cout << num << endl;
  return 0;
}

