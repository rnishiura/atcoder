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
  ll H, W; cin >> H >> W;
  v A(W, 0);
  string in;
  Rep(i, 0, H) {
    cin >> in;
    Rep(j, 0, W) {
      if(in[j] == '#') {
        A[j]++;
      }
    }
  }
  for(auto a: A) {
    cout << a << " ";
  }
  cout << endl;
}
