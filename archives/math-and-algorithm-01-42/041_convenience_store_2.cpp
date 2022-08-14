#include <bits/stdc++.h>
#define POW(z) ((z)*(z))
#define MOD 998244353
using namespace std;
using  ll = long long;
using   v = vector<ll>;
using  vv = vector<vector<ll>>;
using  vp = vector<pair<ll, ll>>;
using vvp = vector<vector<pair<ll, ll>>>;

void print_v(auto &a) {
  for(auto i=a.begin(); i!=a.end(); i++) cout << *i << " ";
  cout << endl;
}
void print_vv(auto &a) {
  for(auto i=a.begin(); i!=a.end(); i++) print_v(*i);
}
void print_vp(auto &a) {
  for(auto i=a.begin(); i!=a.end(); i++) 
    cout << "(" << i->first << "," << i->second << "),";
  cout << endl;
}
void print_vvp(auto &a) {
  for(auto i=a.begin(); i!=a.end(); i++) print_vp(*i);
}
int main(void) {
  ll T, N;
  cin >> T >> N;

  v L(N), R(N);
  for(ll i=0; i<N; i++) cin >> L[i] >> R[i];
  sort(L.begin(), L.end());
  sort(R.begin(), R.end());

  ll lc=0, rc=0, cnt=0;
  for(ll i=0; i<T; i++) {
    for(; lc < N && L[lc]<=i; lc++) cnt++;
    for(; rc < N && R[rc]<=i; rc++) cnt--;
    cout << cnt << endl;
  }
}
