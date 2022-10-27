#include <bits/stdc++.h>
#define MOD 998244353
#define Rep(x, a, b) for(ll x=a; x<b; x++)
#define square(z) ((z)*(z))
#define print(z) cout << z << endl;
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
  ll N;
  cin >> N;

  ll A;
  map<ll, ll> Cnt;
  set<ll> Ord;

  Rep(i, 0, N) {
    cin >> A;
    if(Cnt.find(A) == Cnt.end()) Cnt[A] = 1;
    else Cnt[A] += 1;
    Ord.insert(A);
  }

  ll cnt = 0;
  for(auto it=Ord.crbegin(); it != Ord.crend(); it++) {
    cout << Cnt[*it] << endl;
    cnt++;
  }
  
  Rep(i, cnt, N) cout << 0 << endl;
}
