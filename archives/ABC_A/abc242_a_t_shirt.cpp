#include <bits/stdc++.h>
#define POW(z) ((z)*(z))
#define MOD 998244353
using namespace std;
using  ll = long long;
using   v = vector<ll>;
using  vv = vector<vector<ll>>;
using  vp = vector<pair<ll, ll>>;
using vvp = vector<vector<pair<ll, ll>>>;

void print_v(auto &a) {
  for(auto i=a.begin(); i!=a.end(); i++) cout << *i << " ";
  cout << endl;
}
void print_vv(auto &a) {
  for(auto i=a.begin(); i!=a.end(); i++) print_v(*i);
}
void print_vp(auto &a) {
  for(auto i=a.begin(); i!=a.end(); i++) 
    cout << "(" << i->first << "," << i->second << "),";
  cout << endl;
}
void print_vvp(auto &a) {
  for(auto i=a.begin(); i!=a.end(); i++) print_vp(*i);
}
int main(void) {
  ll A, B, C, X;
  cin >> A >> B >> C >> X;

  if(X <= A) {
    printf("1\n");
  }
  else if(X <= B) {
    printf("%.6lf\n", (double)C / (B-A));
  } 
  else {
    printf("0\n");
  }
}
