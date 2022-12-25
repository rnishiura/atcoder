#include <bits/stdc++.h>
#define Rep(x, a, b) for(ll x=a; x<b; x++)
#define square(z) ((z)*(z))
#define print(z) cout << z << endl;
#define print2(x, y) cout << x << " " << y << endl;
#define MOD 998244353
using namespace std;
using  ll = long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vp  = vector<pair<ll, ll>>;
using vvp = vector<vp>;

int main(void) {
  ll A, B;
  cin >> A >> B;

  ll C = round(1000.0*B/A);
  // cout << C << endl;
  cout << C/1000 << "." << C%1000/100 << C%100/10 << C%10 << endl;
}