#include <bits/stdc++.h>
#define square(z) ((z)*(z))
#define print(z) cout << z << endl;
#define MOD 998244353
using namespace std;
using  ll = long long;
using   v = vector<ll>;
using  vv = vector<vector<ll>>;
using  vp = vector<pair<ll, ll>>;
using vvp = vector<vector<pair<ll, ll>>>;

void print_v(v a) {
  for(auto item: a) cout << item << " ";
  cout << endl;
}
void print_vp(vp a) {
  for(auto p: a) cout << "(" << p.first << " " << p.second << ") ";
  cout << endl;
}
void print_vv(vv a) { for(auto item: a) print_v(item); }
void print_vvp(vvp a) { for(auto item: a) print_vp(item); }

int main(void) {
  ll n, r;
  cin >> r >> n;
  vector<bool> com(n, false);
  fill(com.begin(), com.begin()+r, true);
  do {
    for(ll i=0; i<n; i++) {
      if(com[i]) cout << i+1 << " ";
    }
    cout << endl;
  } while(prev_permutation(com.begin(), com.end()));
  return 0;
}
