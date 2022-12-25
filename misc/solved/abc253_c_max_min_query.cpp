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
  ll N;
  cin >> N;

  ll x, c;
  multiset<ll> ms;
  for(ll i=0; i<N; i++) {
    cin >> x;
    switch(x) {
      case 1:
      cin >> x;
      ms.insert(x);
      break;
      case 2:
      cin >> x >> c;
      for(ll j=0; j<c; j++) {
        auto it = ms.find(x);
        if(it != ms.end()) ms.erase(it);
        else break;
      }
      break;
      case 3:
      cout << *(--ms.end()) - *(ms.begin()) << endl;
    }
  }
}
