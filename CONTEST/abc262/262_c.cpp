#include <bits/stdc++.h>
#define POW(N) ((N)*(N))
using ll = long long;
using namespace std;

void print(auto &v) {
  for(auto itr=v.begin(); itr!=v.end(); itr++) cout << *itr << " ";
  cout << endl;
}

int main(void) {
  ll N;
  cin >> N;


  ll A[N];
  ll cnt = 0;
  for(ll i=0; i<N; i++) {
    cin >> A[i];
    A[i]--;
    // cout << A[i] << " ";
    if (A[i] == i) cnt++;
  }
  ll cnt2=0;
  // cout << endl;
  for(ll i=0; i<N; i++) {
    if (A[i] != i) {
      if (A[A[i]] = i) cnt2++;
    }
  }
  cnt2 /= 2;

  ll sum = 0;
  if (cnt >= 2) {
    sum += cnt*(cnt-1)/2;
  }
  sum += cnt2;
  cout << sum << endl;

}