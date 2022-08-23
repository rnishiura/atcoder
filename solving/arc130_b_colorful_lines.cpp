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
  ll H, W, C, Q;
  cin >> H >> W >> C >> Q;
  
  vector<tuple<ll, ll, ll>> QQ;
  deque<ll> cnt(C+1, 0);
  set<ll> HH, WW;

  ll dH = 0, dW = 0;
  ll t, n, c;
  for(ll i=0; i<Q; i++) {
    cin >> t >> n >> c;
    QQ.push_back(make_tuple(t, n, c));
  } 
  reverse(QQ.begin(), QQ.end());

  for(auto q: QQ) {
    t = get<0>(q);
    n = get<1>(q);
    c = get<2>(q);
    set<ll>& XX = t == 1 ? HH : WW;
    ll& d  = t == 1 ? dH : dW;
    ll& dd = t == 2 ? dH : dW;
    ll& X  = t == 2 ?  H:   W;
    if(XX.find(n) == XX.end()) {
      XX.insert(n);
      d++;
      cnt[c] = X - dd;
    }
  }

  cnt.pop_front();
  for(auto cc: cnt) {
    cout << cc << " ";
  }
  cout << endl;
}
