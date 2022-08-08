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

  vector<ll> A[2];
  ll a;
  for(ll i=0; i<N; i++) {
    cin >> a;
    A[i%2].push_back(a);
  }
  for(auto itr=A[(N+1)%2].rbegin(); itr!=A[(N+1)%2].rend(); itr++) cout << *itr << " ";
  for(auto itr=A[N%2].begin(); itr!=A[N%2].end(); itr++) cout << *itr << " ";
  cout << endl;
}


