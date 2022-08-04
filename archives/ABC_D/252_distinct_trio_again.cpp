#include <iostream>
#include <cmath>

#define MAX_NUM 200000

using namespace std;

int main(void) {
  long N;
  cin >> N;

  long A[MAX_NUM+1];
  for(int i=0; i<=MAX_NUM; i++) A[i] = 0;

  int temp;
  for(int i=0; i<N; i++) {
    cin >> temp;
    A[temp]++;
  }

  long subtractor = 0;
  for(int i=0; i<=MAX_NUM; i++) {
    subtractor += (N-A[i])*A[i]*(A[i]-1)/2 + A[i]*(A[i]-1)*(A[i]-2)/3/2;
  }
  
  cout << N*(N-1)*(N-2)/3/2 - subtractor << endl;
  return 0;
}