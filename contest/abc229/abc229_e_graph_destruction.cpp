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
      parent = (ll*) malloc((n+1)*sizeof(ll));
      for(ll i=0; i<=n; i++) parent[i] = 0;
    }
    void insert(ll n) {
      parent[n] = id;
      --id;
    }
    ll leader(ll n) {
      if(parent[n] < 0) return n;
      return parent[n] = leader(parent[n]);
    }
    bool same(ll a, ll b) {
      return leader(a) == leader(b);
    }
    void merge(ll a, ll b) {
      parent[leader(b)] = leader(a);
    }
  private:
    ll* parent;
    ll  id = -1;
};

int main(void) {
  ll N, M;
  cin >> N >> M;

  vv nodes(N+1);
  ll A, B;
  while(M--) {
    cin >> A >> B;
    nodes[A].push_back(B); 
  }

  graph g(N);
  v ans{0};

  ll new_parent=1;
  for(ll n=N; n>1; n--) {
    ll cnt = 1;
    g.insert(n);
    for(auto i: nodes[n]) {
      if(!g.same(i, n)) {
        g.merge(n, i);
        cnt--;
      }
    }
    ans.push_back(ans.back() + cnt);
    new_parent++;
  }

  reverse(ans.begin(), ans.end());
  for(auto a: ans) cout << a << endl;
}
