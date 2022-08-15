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
  ll N; 
  cin >> N;

  v A(N); 
  for(auto& a: A) cin >> a;

  vector<vv> P;
  vv p, q;
  ll cnt = 0, b;

  for(ll n=1; n<=N; n++) {
    P = vector<vv>();
    p = vv(n+1, v(n, 0)); 
    p[0][0] = 1;
    P.push_back(p);

    for(auto a: A) {
      b = a%n;
      p = vv(n+1, v(n, 0)); 
      p[0][0] = 1;
      q = P.back();
      for(ll i=1; i<=n; i++) {
        for(ll j=0; j<n; j++) {
          p[i][j] = q[i][j] + q[i-1][(j-b+n)%n];
          p[i][j] %= MOD;
        }
      }
      P.push_back(p);
    }
    cnt += P.back()[n][0];
    cnt %= MOD;
  } 
  cout << cnt << endl;
}
