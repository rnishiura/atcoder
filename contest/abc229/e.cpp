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

  vector<set<ll>> nodes(N+1);
  ll A, B;
  while(M--) {
    cin >> A >> B;
    nodes[A].insert(B); 
  }
  
  v ans{0};
  v label(N+1, 0);
  vv reverse_label(N+1);

  ll new_label=1, old_label, last_label=1;
  for(ll n=N; n>0; n--) {
    label[n] = new_label;
    reverse_label[new_label].push_back(n);

    set<ll> unite;
    set<ll> old_label_set;

    for(auto item: nodes[n]) {
      old_label = label[item];
      old_label_set.insert(old_label);
      unite.insert(old_label);
      label[item] = new_label;
    }
    for(auto ol: old_label_set) {
      for(auto r: reverse_label[ol]) {
        reverse_label[new_label].push_back(r);
      }
      reverse_label[ol].clear();
    }
    ans.push_back(ans.back() + 1 - unite.size());
    new_label++;
  }

  for(ll n=N-1; n>=0; n--) {
    cout << ans[n] << endl;
  }
}
