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
void print_vp(vp &a) {
  for(auto i=a.begin(); i!=a.end(); i++) cout << "(" << i->first << "," << i->second << "),";
  cout << endl;
}
void print_vv(vv &a) {for(auto i=a.begin(); i!=a.end(); i++) print_v(*i);}
void print_vvp(vvp &a) {for(auto i=a.begin(); i!=a.end(); i++) print_vp(*i);}

int main(void) {
  ll N, M;
  cin >> N >> M;
  multiset<ll> A;
  multiset<ll> B;
  ll tmp;
  for(ll i=0; i<N; i++) {
    cin >> tmp;
    A.insert(tmp);
  }
  for(ll i=0; i<M; i++) {
    cin >> tmp;
    B.insert(tmp);
  }
  for(auto itr=B.begin(); itr!=B.end(); itr++) {
    auto aitr = A.find(*itr);
    if(aitr == A.end()) {
      cout << "No" << endl;
      return 0;
    } 
    A.erase(aitr);
  }
  cout << "Yes" << endl;
}
