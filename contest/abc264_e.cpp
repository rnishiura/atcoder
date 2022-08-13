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
  v event;
  ll Q;
  cin >> Q;
  for(ll i=0; i<Q; i++) {
    cin >> u[0];
    event.push_back(u[0]);
  }
  for(ll i=0; i<Q; i++) {
    pair p = wire[event[i]];
    nodes[p.first].erase(p.second);
    nodes[p.second].erase(p.first);
    set<ll> dark;
    for(ll city=1; city<=N; city++) {
      if(dark.find(city) != dark.end()) continue;
      set<ll> searched;
      set<ll> edge;
      edge.insert(city);
      while(edge.size() > 0) {
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
      if(!flg) {
        for(auto it=searched.begin(); it!=searched.end(); it++) {
          dark.insert(*it);
        }
      }
    }
    cout << N-dark.size() << endl;
  }
}
