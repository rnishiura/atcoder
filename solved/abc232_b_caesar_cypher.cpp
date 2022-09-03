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
  string S, T;
  cin >> S >> T;

  int d = (int)(T[0]-S[0]+26) % 26;
  bool flg = true;
  for(ll i=0; i<S.length(); i++) {
    int e = (int)(T[i]-S[i]+26) % 26;
    if(d != e) {
      flg = false;
      break;
    }
  }
  if (flg) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
