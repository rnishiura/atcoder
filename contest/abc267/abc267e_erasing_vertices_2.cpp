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
  ll N, M;
  cin >> N >> M;
  
  ll tmp;
  v A(N+1, 0);
  for(ll i=1; i<=N; i++) cin >> A[i];

  ll u[2];
  v S(N+1);

  vector<set<ll>> C(N+1);
  for(ll i=0; i<M; i++) {
    for(ll j=0; j<2; j++) cin >> u[j];
    for(ll j=0; j<2; j++) {
      S[u[1-j]] += A[u[j]];
      C[u[1-j]].insert(u[j]);
    }
  }

  set<pair<ll, ll> SS;
  for(ll i=0; i<=N; i++) {
    SS.insert(make_pair(S[i], i));
  }

  ll max_val = 0;
  S[0] = INT64_MAX;
  for(ll i=0; i<N; i++) {
    auto ss = SS.begin();
    max_val = max(max_val, ss->first);
    SS.erase(ss);
    for(auto c: C[ss->second]) {
      S[c] -= A[ss->second];
    } 
  }

  print(max_val);
}
