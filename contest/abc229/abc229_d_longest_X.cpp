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
  string S;
  ll K;
  cin >> S >> K;

  ll l=0, r=0, ans=0;
  for(; r<S.length(); l++)  {
    if(l > 0 && S[l-1] == '.') {
      K++;
    }
    for(; r<S.length(); r++) {
      if(S[r] == '.') {
        if(K == 0) break;
        K--;
      }
    }
    ans = max(ans, r-l);
  }
  cout << ans << endl;
}
