#include <bits/stdc++.h>
#define POW(z) ((z)*(z))
#define MOD 998244353
using namespace std;
using  ll = long long;
using   v = vector<ll>;
using  vv = vector<vector<ll>>;
using  vp = vector<pair<ll, ll>>;
using vvp = vector<vector<pair<ll, ll>>>;

void print_v(v &a) {
  for(auto i=a.begin(); i!=a.end(); i++) cout << *i << " ";
  cout << endl;
}
void print_vp(vp &a) {
  for(auto i=a.begin(); i!=a.end(); i++) cout << "(" << i->first << "," << i->second << "),";
  cout << endl;
}
void print_vv(vv &a) {for(auto i=a.begin(); i!=a.end(); i++) print_v(*i);}
void print_vvp(vvp &a) {for(auto i=a.begin(); i!=a.end(); i++) print_vp(*i);}

string i2b(ll s, ll n) {
  string ret = "";
  for(ll i=0; i<n; i++) {
    if(s % 2) ret = "1" + ret;
    else ret = "0" + ret;
    s /= 2;
  }
  return ret;
}
int main(void) {
  ll N, K;
  cin >> N >> K;
  vector<string> S;
  string s;
  for(ll i=0; i<N; i++) {
    cin >> s;
    S.push_back(s);
  }
  ll max_val = 0;
  ll size = 1;
  for(ll i=0; i<N; i++) size *= 2;
  for(ll i=0; i<size; i++) {
    map<char, ll> m;
    for(char c='a'; c<='z'; c++) m[c] = 0;
    string b = i2b(i, N);
    for(ll j=0; j<N; j++) {
      if(b[j] == '1') {
        for(ll k=0; k<S[j].length(); k++) {
          m[S[j][k]]++;
        }
      }
    }
    ll val = 0;
    for(char c='a'; c<='z'; c++) if(m[c] == K) val++;
    max_val = max(max_val, val);
  }
  cout << max_val << endl;
}
