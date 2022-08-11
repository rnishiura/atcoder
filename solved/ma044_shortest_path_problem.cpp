#include <bits/stdc++.h>
#define POW(z) ((z)*(z))
#define MOD 998244353
using namespace std;
using  ll = long long;
using   v = vector<ll>;

void print(auto &v) {
  for(auto itr=v.begin(); itr!=v.end(); itr++) cout << *itr << " ";
  cout << endl;
}

int main(void) {
  ll N, M;
  cin >> N >> M;

  // let's input'em
  v u(2);
  vector<set<ll>> vs(N+1);
  for(ll i=0; i<M; i++) {
    cin >> u[0] >> u[1];
    for(ll j=0; j<2; j++) vs[u[j]].insert(u[1-j]);
  }

  set<ll> past;
  vector<set<ll>> stage(1);

  // start from...
  stage[0].insert(1);
  past.insert(1);

  for(ll i=0; stage[i].size() > 0; i++) {
    set<ll> next;
    for(auto it = stage[i].begin(); it != stage[i].end(); it++) {
      for(auto itt = vs[*it].begin(); itt != vs[*it].end(); itt++) {
        if(past.find(*itt) == past.end()) {
          next.insert(*itt);
          past.insert(*itt);
        }
      }
    }
    stage.push_back(next);
  }

  map<ll, ll> memo;
  for(ll i=0; i<stage.size()-1; i++) {
    for(auto it = stage[i].begin(); it != stage[i].end(); it++) {
      memo[*it] = i;
    }
  }

  for(ll i=1; i<=N; i++) {
    if(memo.find(i) != memo.end()) {
      cout << memo[i] << endl;
    } else {
      cout << -1 << endl;
    }
  }
}
