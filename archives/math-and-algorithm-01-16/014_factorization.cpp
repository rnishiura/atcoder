#include <bits/stdc++.h>
#define POW(z) ((z)*(z))
#define MOD 998244353
using namespace std;
using  ll = long long;
using   v = vector<ll>;
using  vv = vector<vector<ll>>;
using  vp = vector<pair<ll, ll>>;
using vvp = vector<vector<pair<ll, ll>>>;

void print_v(v &a) {
  for(auto i=a.begin(); i!=a.end(); i++) cout << *i << " ";
  cout << endl;
}
void print_vv(vv &a) {
  for(auto i=a.begin(); i!=a.end(); i++) print_v(*i);
}
void print_vp(vp &a) {
  for(auto i=a.begin(); i!=a.end(); i++) 
    cout << "(" << i->first << "," << i->second << "),";
  cout << endl;
}
void print_vvp(vvp &a) {
  for(auto i=a.begin(); i!=a.end(); i++) print_vp(*i);
}

void prime(v &a, ll N) {
  vector<bool> tmp(N+1, true);
  ll end = sqrt(N+1)+1;
  for(ll i=2; i<=end; i++) {
    while(!tmp[i] && i<=end) i++;
    for(ll j=2; i*j<=N; j++) tmp[i*j] = false;
  }
  a.empty();
  for(ll i=2; i<=N; i++) if(tmp[i]) a.push_back(i);
}

int main(void) {
  ll N;
  cin >> N;

  v a;
  prime(a, sqrt(N+1)+1);

  ll n = N;
  for(ll i=0; i<a.size(); i++) {
    for(; !(n%a[i]); n/=a[i]) cout << a[i] << " ";
  }
  if(n > 1) cout << n << endl;
  else cout << endl;
}

