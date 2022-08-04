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
  string S;
  cin >> S;
  vector<ll> L, R;
  for(ll i=1; i<=N; i++) {
    if (S[i-1] == 'L') 
      R.push_back(i-1);
    else
      L.push_back(i-1);
  }

  for(auto itr=L.begin(); itr!=L.end(); itr++) cout << *itr << " ";
  cout << N << " ";
  for(auto itr=R.rbegin(); itr!=R.rend(); itr++) cout << *itr << " ";
  cout << endl;
}


