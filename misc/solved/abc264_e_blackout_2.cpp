#include <bits/stdc++.h>
using namespace std;
using  ll = long long;
using   v = vector<ll>;
using  vv = vector<vector<ll>>;
using  vp = vector<pair<ll, ll>>;

struct graph {
  public:
    graph(ll n) {
      parent = (ll*) malloc((n+1)*sizeof(ll));
      for(ll i=0; i<=n; i++) parent[i] = -1;
    }
    ll size(ll n) {
      return -parent[leader(n)];
    }
    ll leader(ll n) {
      if(parent[n] < 0) return n;
      else return parent[n] = leader(parent[n]);
    }
    bool same(ll a, ll b) {
      return leader(a) == leader(b);
    }
    void merge(ll a, ll b) {
      ll x = leader(a), y = leader(b);
      if(x == y) return;
      parent[leader(a)] += parent[leader(b)];
      parent[leader(b)] = leader(a);
    }
  private:
    ll* parent;
};

int main(void) {
  ll N, M, E;
  cin >> N >> M >> E;

  vp wires(E+1);
  set<ll> valid_wires;
  v erased_wires;

  ll a, b;
  for(ll i=1; i<=E; i++) {
    cin >> a >> b;
    wires[i] = make_pair(a, b);
    valid_wires.insert(i);
  }

  ll Q, e;
  cin >> Q;
  for(ll i=0; i<Q; i++) {
    cin >> e;
    erased_wires.push_back(e);
    valid_wires.erase(e);
  }
  
  reverse(erased_wires.begin(), erased_wires.end());
  erased_wires.pop_back();

  graph g(N+M);

  ll cnt = 0;
  for(auto i: valid_wires) {
    a = get<0>(wires[i]);
    b = get<1>(wires[i]);
    g.merge(a, b);
  }

  set<ll> pow_leader;
  for(ll i=N+1; i<=N+M; i++) pow_leader.insert(g.leader(i));

  for(ll i=1; i<=N; i++) {
    if(pow_leader.find(g.leader(i)) != pow_leader.end()) {
      cnt++;
    }
  }

  v c{cnt};
  for(auto e: erased_wires) {
    a = get<0>(wires[e]);
    b = get<1>(wires[e]);

    if(g.same(a, b)) {
      c.push_back(cnt);
      continue;
    }

    bool a_pow = pow_leader.find(g.leader(a)) != pow_leader.end();
    bool b_pow = pow_leader.find(g.leader(b)) != pow_leader.end();

    if (a_pow and b_pow) {
      pow_leader.erase(b);
      g.merge(a, b);
    } else if(a_pow) {
      cnt += g.size(b);
      g.merge(a, b);
    } else if(b_pow) {
      cnt += g.size(a);
      g.merge(b, a);
    } else {
      g.merge(a, b);
    }
    c.push_back(cnt);
  }

  reverse(c.begin(), c.end());
  for(auto ans: c) {
    cout << ans << endl;
  }
}

