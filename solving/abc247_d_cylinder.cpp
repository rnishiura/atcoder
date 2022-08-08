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

int main(void) {
  ll N;
  cin >> N;

  ll x, c, op = 0;
  vp cylinder;
  // cylinder.push_back(make_pair(3,3));
  // cylinder[0] = make_pair(2,2);
  for(ll i=0; i<N; i++) {
    cin >> x;
    switch(x) {
      case 1:
      cin >> x >> c;
      cylinder.push_back(make_pair(x, c));
      break;
      case 2:
      cin >> c;
      ll sum_val = 0;
      while (c>0) {
        pair p = cylinder[op];
        if(p.second > c) {
          sum_val += p.first * c;
          cylinder[op] = make_pair(p.first, p.second-c);
          c = 0;
          break;
        } else {
          sum_val += p.first * p.second;
          c -= p.second;
          op++;
        }
      }
      cout << sum_val << endl;
      break;
    }
  }
  // print_vp(cylinder);
}
