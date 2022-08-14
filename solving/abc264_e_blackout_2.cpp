#include <bits/stdc++.h>
using namespace std;
using  ll = long long;
using   v = vector<ll>;
using  vv = vector<vector<ll>>;
using  vp = vector<pair<ll, ll>>;

int main(void) {
  ll N, M, E;
  cin >> N >> M >> E;
  vp wire(E+1);
  v u(2);
  vector<set<ll>> nodes(N+M+1);
  for(ll i=1; i<=E; i++) {
    cin >> u[0] >> u[1];
    wire[i] = make_pair(u[0], u[1]);
    for(ll j=0; j<2; j++) nodes[u[j]].insert(u[1-j]);
  }

  ll dark_cnt = N;
  set<ll> pool;
  for(ll j=1; j<=N; j++) {
    if(pool.find(j) != pool.end()) continue;
    set<ll> searched;
    set<ll> edge;
    edge.insert(j);
    while(edge.begin() != edge.end()) {
      auto e = edge.begin();
      set<ll> d = nodes[*e];
      searched.insert(*e);
      edge.erase(e);
      for(auto it=d.begin(); it!=d.end(); it++) {
        if (searched.find(*it) == searched.end()) edge.insert(*it);
      }
    }
    bool flg = false;
    for(auto it=searched.begin(); it!=searched.end(); it++) {
      if(*it >= N+1) {
        flg = true;
        break;
      }
    }
    if(flg) {
      for(auto it=searched.begin(); it!=searched.end(); it++) {
        if(*it <= N) {
          pool.insert(*it);
          --dark_cnt;
        }
      }
    }
  }

  ll event, Q;
  cin >> Q;
  for(ll i=0; i<Q; i++) {
    cin >> event;
    u[0] = wire[event].first;
    u[1] = wire[event].second;
    for(ll j=0; j<2; j++) nodes[u[j]].erase(u[1-j]);
    for(ll j=0; j<2; j++) {
      if(pool.find(u[j]) == pool.end()) continue;
      set<ll> searched;
      set<ll> edge;
      edge.insert(u[j]);
      bool flg = false;
      while(edge.begin() != edge.end()) {
        auto e = edge.begin();
        set<ll> d = nodes[*e];
        if (*e >= N+1) {
          flg = true;
          break;
        }
        searched.insert(*e);
        edge.erase(e);
        for(auto it=d.begin(); it!=d.end(); it++) {
          if (searched.find(*it) == searched.end()) edge.insert(*it);
        }
      }
      if(!flg) {
        for(auto it=searched.begin(); it!=searched.end(); it++) {
          if (pool.find(*it) != pool.end()) {
            pool.erase(*it);
            ++dark_cnt;
          }
        }
      }
    }
    cout << N-dark_cnt << endl;
  }
}

