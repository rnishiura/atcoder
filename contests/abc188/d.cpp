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
  ll N, C;
  cin >> N >> C;

  deque<tuple<ll, ll, bool>> vec;
  ll a, b, c;
  for(ll i=0; i<N; i++) {
    cin >> a >> b >> c;
    vec.push_back(make_tuple(a, c, true));
    vec.push_back(make_tuple(b+1, c, false));
  }

  sort(vec.begin(), vec.end());

  ll prev=get<0>(vec.front()), prc=get<1>(vec.front()), total=0;
  vec.pop_front();
  for(auto v: vec) {
    total += min(C, prc) * (get<0>(v)-prev);
    if(get<2>(v)) {
      prc += get<1>(v);
    } else {
      prc -= get<1>(v);
    }
    prev = get<0>(v);
  }
  cout << total << endl;
}
