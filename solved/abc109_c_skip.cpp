#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll gcd(ll a, ll b) {
  if (a < b) swap(a, b);
  if (a%b==0) return b;
  else return gcd(b, a%b);
}

int main(void) {
  ll N, X;
  cin >> N >> X;
  ll x, t;
  cin >> x;
  x = llabs(x-X);
  for(ll i=1; i<N; i++) {
    cin >> t;
    x = gcd(x, llabs(t-X));
  }
  cout << x << endl;
}


