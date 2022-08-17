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
void print_vv(vv a) { 
  for(auto item: a) print_v(item); 
}
void print_vp(vp a) {
  for(auto item: a) cout << "(" << item.first << " " << item.second << ") ";
  cout << endl;
}
void print_vvp(vvp a) { 
  for(auto item: a) print_vp(item); 
}

int main(void) {
  ll N, W;
  cin >> N >> W;

  vp AB;
  ll A, B;
  for(ll i=0; i<N; i++) {
    cin >> A >> B;
    AB.push_back(make_pair(A, B));
  }
  sort(AB.rbegin(), AB.rend());
  // print_vp(AB);

  ll ans = 0;
  for(auto p: AB) {
    ans += p.first * min(W, p.second);
    W -= p.second;
    if(W <= 0) break;
  }
  cout << ans << endl;
}
