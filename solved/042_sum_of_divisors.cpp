#include <bits/stdc++.h>
#define POW(z) ((z)*(z))
#define MOD 998244353
using ll = long long;
using namespace std;

void print(auto &v) {
  for(auto itr=v.begin(); itr!=v.end(); itr++) cout << *itr << " ";
  cout << endl;
}

int main(void) {
  ll N;
  cin >> N;

  vector<ll> P(N+1, 1);
  
  ll i=2, j, cnt, n;
  while (i <= N) {
    j = 1;
    while (i*j <= N) {
      cnt = 0;
      n = i*j;
      while(!(n%i)) {
        n /= i;
        cnt++;
      }
      P[i*j] *= ++cnt;
      j++;
    }
    i++;
    while(i<=N && P[i]>1) i++;
  }
  ll sum = 0;
  for(ll i=1; i<=N; i++) {
    sum += i * P[i];
  }
  cout << sum << endl;
}


