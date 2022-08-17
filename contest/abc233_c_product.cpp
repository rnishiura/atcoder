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
  ll N, X, L, a;
  cin >> N >> X;

  vector<multiset<ll>> hist(1);
  hist.back().insert(1);
  for(ll i=0; i<N; i++) {
    cin >> L;
    multiset<ll> prod;
    for(ll j=0; j<L; j++) {
      cin >> a;
      for(auto item: hist.back()) {
        if (a*item <= X) prod.insert(a*item);
      }
    } 
    hist.push_back(prod);
  }
  cout << hist.back().count(X) << endl;

}
