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
  ll N, M;
  cin >> N >> M;

  ll A[N+1];
  for(ll i=1; i<=N; i++) {
    cin >> A[i];
  }

  vector<set<ll>> nodes(N+1);
  v u(2);
  for(ll i=0; i<M; i++) {
    cin >> u[0] >> u[1];
    for(ll j=0; j<2; j++) {
      nodes[u[j]].insert(u[1-j]);
    }
  }

  ll n;
  set<ll> searched;
  vector<tuple<set<ll>::iterator, ll, ll>> stack;
  ll best = INT64_MIN;

  for(ll i=1; i<=N; i++) 
  {
    n = i;
    if(searched.find(i) != searched.end()) continue;
    ll min_val = A[n];
    set<ll>::iterator itr = nodes[n].begin();
    do {
      cout << *itr << endl;
      // searched.insert(*itr);
      // min_val = min(min_val, A[*itr]);
      // best = max(best, A[*itr]-min_val);
      // stack.push_back(make_tuple(itr, n, min_val));
      if(nodes[*itr].begin() == nodes[*itr].end()) {
        break;
        // do {
        //   tuple<set<ll>::iterator, ll, ll> t = stack.back();
        //   itr     = get<0>(t);
        //   n       = get<1>(t);
        //   min_val = get<2>(t);
        //   itr++;
        //   stack.pop_back();
        // } while(itr == nodes[n].end());
      }
      // itr = nodes[*itr].begin();
      itr++;
      if(itr == nodes[n].end()) break;
    } while(true);
    // } while(stack.size());
  }
  cout << best << endl;
}
