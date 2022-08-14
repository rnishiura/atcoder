#include <bits/stdc++.h>
#define square(z) ((z)*(z))
#define print(z) cout << z << endl;
#define MOD 1000000007
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
  ll a, b;
  cin >> a >> b;

  ll n;
  v p{a};
  for(n=1; (1<<n) <= b; n++) {
    a *= a;
    a %= MOD;
    p.push_back(a);
  }
  n--;

  ll r=1;
  for(; b>0; n--) {
    if (b/(1<<n)) {
      // cout << n << " " << (1<<n) << endl;
      r *= p[n];
      r %= MOD;
      b %= 1<<n;
    }
  }
  cout << r << endl;
  // print_v(p);
}
