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

  ll L, R, M;
  ll min_val = INT64_MAX;
  bool flg;
  for(ll i=0; i<N; i++) {
    L = 0;
    R = 4000000000;
    
    while(true) {
      M = (L+R)/2;

      set<ll> pool;
      vector<set<ll>> stage(1);

      pool.insert(i);
      stage[0].insert(i);
      while(stage[stage.size()-1].size()) {
        set<ll> new_stage;
        for(auto item: stage[stage.size()-1]) {
          for(ll j=0; j<N; j++) {
            if(P[item]*M >= abs(X[item]-X[j]) + abs(Y[item]-Y[j])) {
              if(pool.find(j) == pool.end()) {
                pool.insert(j);
                new_stage.insert(j);
              }
            }
          }
        }
        stage.push_back(new_stage);
      }

      flg = N == pool.size();

      if(L+1 >= R) break;

      if(flg) {
        R = M;
      } else {
        L = M;
      }
    }

    if(flg) {
      M = L;
    } else  {
      M = R;
    }

    min_val = min(min_val, M);
  }
  cout << min_val << endl;
}

// 始点の全探索（最小のジャンプ力)
// - ジャンプ力の二分探索（始点からすべての点に行ける最小のジャンプ力）

