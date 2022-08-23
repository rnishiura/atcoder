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
  ll N, M, K;
  cin >> N >> M >> K;

  v A(N);
  ll max_val = 0;
  for(ll i=0; i<N; i++) {
    cin >> A[i];
    max_val = max(max_val, A[i]);
  }

  ll X;
  for(ll i=0; i<max_val+M; i++)  {
    X = i+1;
    set<ll> pool;

    // todo DP
    for(auto a: A) {
      pool.insert(X - a%(X+1));
    }

    ll sum_val = 0, idx=0;
    for(auto p: pool) {
      sum_val += p;
      if(++idx >= K) break; 
    }
    cout << X << " " << sum_val << endl;

  }

  // for(auto item: A) {
  //   cout << 461-item << endl;
  // }

  // ll L = 0, R = 1LL << 32, X;

  // while(true) {
  //   X = (L+R) / 2;
  //   cout << X << endl;
  //   set<ll> pool;

  //   // todo DP
  //   for(auto a: A) {
  //     pool.insert(X - a%(X+1));
  //   }

  //   ll sum_val = 0, idx=0;
  //   for(auto p: pool) {
  //     sum_val += p;
  //     if(++idx >= K) break; 
  //   }

  //   if(sum_val <= M) {
  //     L = X;
  //   } else {
  //     R = X;
  //   }
  //   if(R-L < 2) {
  //     cout << R-L << endl;
  //     break; 
  //   }
  // }

  // cout << L << " " << R << endl;

}
