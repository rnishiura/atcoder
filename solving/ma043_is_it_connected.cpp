#include <bits/stdc++.h>
#define POW(z) ((z)*(z))
#define MOD 998244353
using namespace std;
using  ll = long long;
using   v = vector<ll>;
using  vv = vector<vector<ll>>;
using  vp = vector<pair<ll, ll>>;
using vvp = vector<vector<pair<ll, ll>>>;

void print_v(auto &a) {
  for(auto i=a.begin(); i!=a.end(); i++) cout << *i << " ";
  cout << endl;
}
void print_vv(auto &a) {
  for(auto i=a.begin(); i!=a.end(); i++) print_v(*i);
}
void print_vp(auto &a) {
  for(auto i=a.begin(); i!=a.end(); i++) 
    cout << "(" << i->first << "," << i->second << "),";
  cout << endl;
}
void print_vvp(auto &a) {
  for(auto i=a.begin(); i!=a.end(); i++) print_vp(*i);
}

int main(void) {
  ll N, M;
  cin >> N >> M;

  vector<set<ll>> connect(N);
  vector<bool> valid(N, false);
  ll u, v;
  for(ll i=0; i<M; i++) {
    cin >> u >> v;
    u--; v--;
    connect[u].insert(v);
    connect[v].insert(u);
  }
  // print_vv(connect);
  ll i = 0, prev_i;
  auto itr = connect[i].begin();
  do {
    valid[i] = true;
    prev_i = i;
    i = *itr;
    itr = connect[i].find(prev_i);
    if(++itr == connect[i].end()) itr = connect[i].begin();
  } while(i);

  // print_v(valid);

  itr = connect[i].begin();
  do {
    valid[i] = true;
    prev_i = i;
    i = *itr;
    itr = connect[i].find(prev_i);
    if(itr == connect[i].begin()) itr = --connect[i].end();
    else --itr;
  } while(i);

  // print_v(valid);
  for(ll i=0; i<N; i++) {
    if(!(valid[i])) {
      cout << "The graph is not connected." << endl;
      return 0;
    }
  }
  cout << "The graph is connected." << endl;
}
