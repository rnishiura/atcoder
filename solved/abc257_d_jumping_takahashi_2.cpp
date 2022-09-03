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

void print_v(v &a) {
  for(auto i=a.begin(); i!=a.end(); i++) cout << *i << " ";
  cout << endl;
}
void print_vp(vp &a) {
  for(auto i=a.begin(); i!=a.end(); i++) 
    cout << "(" << i->first << "," << i->second << "),";
  cout << endl;
}
void print_vv(vv &a) {
  for(auto i=a.begin(); i!=a.end(); i++) print_v(*i);
}
void print_vvp(vvp &a) {
  for(auto i=a.begin(); i!=a.end(); i++) print_vp(*i);
}

int main(void) {
  ll N;
  cin >> N;

  v X(N), Y(N), P(N);
  for(ll i=0; i<N; i++) cin >> X[i] >> Y[i] >> P[i];

  ll min_val = INT64_MAX;

  ll L, R, M;
  bool flg;
  for(ll i=0; i<N; i++) {
    L = 0;
    R = 4000000000;
    while(true) {
      M = (L+R)/2;

      set<ll> pool;
      vector<set<ll>> stage(1);
      pool.insert(i);
      stage.front().insert(i);
      while(stage.back().begin() != stage.back().end()) {
        set<ll> next;
        for(auto from: stage.back()) {
          for(ll to=0; to<N; to++) {
            if(P[from]*M >= abs(X[to]-X[from]) + abs(Y[to]-Y[from])) {
              if(pool.find(to) == pool.end()) {
                pool.insert(to);
                next.insert(to);
              }
            }
          }
        }
        stage.push_back(next);
      }
      flg = (pool.size() == N);
    
      if(R-L<2) {
        if(flg)
          M = L;
        else
          M = R;
        break;
      }
      if(flg) {
        R = M;
      } else {
        L = M;
      }
    }
    min_val = min(M, min_val);
  }
  cout << min_val << endl;
}
