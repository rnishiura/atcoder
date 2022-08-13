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

int main(void) {
  ll a1 = 1, a2 = 1, tmp;
  set<pair<ll, ll>> memo;
  memo.insert(make_pair(1, 1));

  // ll N;
  // cin >> N;
  // for(ll i=0; i<N-2; i++) {
  while (true) {
    tmp = a1;
    a1 = a1+a2;
    a2 = tmp;
    a1 %= MOD;
    if(memo.find(make_pair(a1, a2)) == memo.end()) {
      memo.insert(make_pair(a1, a2));
    } else {
      cout << a1 << " " << a2 << endl;
      break;
    }
    cout << ".";
  }
  cout << a1 << endl;
}
