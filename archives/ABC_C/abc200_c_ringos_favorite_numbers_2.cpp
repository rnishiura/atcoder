#include <bits/stdc++.h>
#define POW(N) (N*N)
using ll = long long;
using namespace std;

int main(void) {
  ll N;
  cin >> N;

  ll A[200];
  for(ll i=0; i<200; i++) A[i] = 0;
  ll tmp;
  ll cnt = 0;
  
  for(ll i=0; i<N; i++) {
    cin >> tmp;
    A[tmp%200]++;
  }
  for(ll i=0; i<200; i++) {
    cnt += A[i]*(A[i]-1)/2;
  }
  cout << cnt << endl;
}

