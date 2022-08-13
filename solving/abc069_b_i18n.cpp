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

int main(void) {
  string s;
  cin >> s;

  cout <<s[0] <<s.length() - 2 <<s[s.length()-1] <<endl; 

}
