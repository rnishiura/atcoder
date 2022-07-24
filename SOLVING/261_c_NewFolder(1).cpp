#include <bits/stdc++.h>
#define POW(N) ((N)*(N))
using ll = long long;
using namespace std;

int main(void) {
  ll N;
  cin >> N;

  map<string, ll> memo;

  string s;
  for(ll i=0; i<N; i++) {
    cin >> s;
    if (memo.find(s) == memo.end()) {
      cout << s << endl;
      memo[s] = 1;
    } else {
      cout << s << "(" << memo[s] << ")" << endl;
      memo[s] += 1;
    }
  }

}

