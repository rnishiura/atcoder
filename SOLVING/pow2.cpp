#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll pow1(ll a) { return pow(a, 2); }

ll pow2(ll a) { return (ll)(pow(a, 2)+0.1); }

ll pow3(ll a) { return a * a; }

void study1(void) {
  ll N = 100000000;
  for(ll i=0; i<N; i++){
    if(pow1(i) != pow3(i)) {
      cout << i << endl;
      // cout << pow(i, 2) << endl;
      printf("%lf\n", pow(i, 2));
      cout << pow1(i) << endl;
      cout << pow2(i) << endl;
      cout << pow3(i) << endl;
      break;
    }
  }
}

void study2(void) {
  ll N;
  cin >> N;
  printf("%lf\n", pow((double)N, (double)2));
  cout << pow1(N) << endl;
  cout << pow2(N) << endl;
  cout << pow3(N) << endl;
}

int main(void) {
  cout << __INT64_MAX__ << endl;
  cout << __INT32_MAX__ << endl;
  // cout << DBL_MAX << endl;
  // study1();
  // study2();
  printf("%lf\n", pow(999999999.0, 2.0));
  // cout << (ll)(double)999999998000000001 << endl;
}