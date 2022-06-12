#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(void) {
  int N, K;
  cin >> N >> K;

  int A[K];
  for(int i=0; i<K; i++) {
    cin >> A[i];
    --A[i];
  }

  double XY[N][2];
  for(int i=0; i<N; i++) {
    cin >> XY[i][0] >> XY[i][1];
  } 

  double max_r = DBL_MIN;
  for(int i=0; i<N; i++) {
    double min_r = DBL_MAX;
    for(int j=0; j<K; j++) {
      double dist = sqrt( pow( XY[i][0]-XY[A[j]][0] , 2) + pow( XY[i][1]-XY[A[j]][1] , 2) );
      min_r = min(min_r, dist);
    }
    max_r = max(max_r, min_r);
  }
  cout.precision(17);
  cout << max_r << endl;
}
