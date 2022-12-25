#include <bits/stdc++.h>
#define rep(x, n)      for(ll x=0; x<n; x++)
#define repi(x, a, b)  for(ll x=a; x<b; x++)
#define rrep(x, n)     for(ll x=n-1; x>=0; x--)
#define rrepi(x, a, b) for(ll x=b-1; x>=a; x--)
#define MOD 998244353
#define LL_MAX_S (1LL<<62)
#define DOUBLE_MAX_S ((double)LL_MAX_S)
#define print(z) cout << (z) << endl
#define print2(x, y) cout << (x) << " " << (y) << endl
#define square(z) ((z)*(z))
#define contains(x, s) (s.find(x) != s.end())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
using ll  = long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vp  = vector<pair<ll, ll>>;
using vvp = vector<vp>;

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
  ll n, m;
  cin >> n >> m;

  graph G(n);
  vv g(m);
  ll a, b, c;
  rep(i, m) {
    cin >> a >> b >> c;
    g[i] = {a, b, c};
  }
  sort(g.begin(), g.end(), [](v& p, v&q) {return p[2] < q[2];});

  ll ret = 0;
  rep(i, m) {
    if(!G.same(g[i][0], g[i][1])) {
      G.merge(g[i][0], g[i][1]);
      ret += g[i][2];
    }
  }

  print(ret);
}
