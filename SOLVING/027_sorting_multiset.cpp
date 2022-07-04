#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(void) {
  int N;
  cin >> N;
  multiset<ll> ms;
  ll tmp;
  for(ll i=0; i<N; i++) {
    cin >> tmp;
    ms.insert(tmp);
  }
  for(auto itr = ms.begin(); itr != ms.end(); itr++) {
    cout << *itr << " ";
  }
  cout << endl;
}
