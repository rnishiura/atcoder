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
  string S; cin >> S;
  ll N = S.length();
  v T;
  Rep(i, 0, N) T.push_back(S[i]);

  for(char x='a'; x <= 'z'; x++) {
    v U;
    ll cnt=0;
    Rep(i, 0, N-1) {
      if(T[i] == x)
      U.push_back(T[i]);
    })


    N--;
  }
  
}