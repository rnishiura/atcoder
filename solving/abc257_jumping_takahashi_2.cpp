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
  ll min_S = INT64_MAX;
  bool flg;
  for(ll i=0; i<N; i++) {
    L = 0;
    R = 4000000000;
    while(true) {
      M = (L+R)/2;
      flg = false;
      
      // BFS
      set<ll> pool;
      vector<set<ll>> stage(1);
      ll si=0;
      stage[si].insert(i);
      pool.insert(i);
      while( stage[si].size() ) {
        set<ll> next;
        for(auto it=stage[si].begin(); it != stage[si].end(); it++) {
          for(ll j=0; j<N; j++) {
            if(pool.find(j) != pool.end()) continue;
            if(M*P[*it] >= abs(X[*it]-X[j]) + abs(Y[*it]-Y[j])) {
              next.insert(j);
              pool.insert(j);
            }
          }
        }
        stage.push_back(next);
        si++;
      }

      flg = pool.size() == N;

      // end if L and R is adjacent
      if(L+1>=R) {
        // cout << L << " " << R << endl;
        // cout << pool.size() << endl;
        break;
      }

      // if fully connected
      if(flg) 
        R = M;
      else 
        L = M;
    }

    // flg is for L else R
    if(flg) 
      M = L;
    else 
      M = R;

    min_S = min(min_S, M);
  }
  cout << min_S << endl;
}

// 始点の全探索（最小のジャンプ力)
// - ジャンプ力の二分探索（始点からすべての点に行ける最小のジャンプ力）

