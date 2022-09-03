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

struct graph {
  public:
    graph(ll n) {
      _n = n;
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
    void show_leaders() {
      for(ll i=1; i<=_n; i++) cout << leader(i) << " ";
      cout << endl;
    }
    void show_sizes() {
      for(ll i=1; i<=_n; i++) cout << size(i) << " ";
      cout << endl;
    }
  private:
    ll  _n;
    ll* parent;
};

int main(void) {
  ll N;
  cin >> N;

  graph g(N);

  ll a, b;

  while(true) {
    cin >> a >> b;
    g.merge(a, b);
    g.show_leaders();
    g.show_sizes();
  }
}
