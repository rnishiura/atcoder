#include <bits/stdc++.h>
#define POW(z) ((z)*(z))
#define MOD 998244353
using namespace std;
using  ll = long long;
using   v = vector<ll>;

void print(auto &v) {
  for(auto itr=v.begin(); itr!=v.end(); itr++) cout << *itr << " ";
  cout << endl;
}

int main(void) {
  ll H, W;
  cin >> H >> W;
  ll sx, sy, gx, gy;
  cin >> sy >> sx >> gy >> gx;
  sx--, sy--, gx--, gy--;

  // let's input'em
  vector<string> path(H);
  for(ll i=0; i<H; i++) {
    cin >> path[i];
  }

  set<pair<ll, ll>> past;
  set<pair<ll, ll>> stage;


  // start from...
  stage.insert(make_pair(sx, sy));
  past.insert(make_pair(sx, sy));

  ll i;
  set<pair<ll, ll>> sub;
  sub.insert(make_pair(1,0));
  sub.insert(make_pair(0,1));
  sub.insert(make_pair(-1,0));
  sub.insert(make_pair(0,-1));

  for(i=0; true; i++) {
    // cout << i+1 << endl;
    set<pair<ll, ll>> prev_stage = stage;
    stage.clear();

    for(auto it=prev_stage.begin(); it != prev_stage.end(); it++) {
      // cout << it->first << " " << it->second << "#" << endl;
      for(auto si=sub.begin(); si != sub.end(); si++) {
        ll x = it->first  + si->first;
        ll y = it->second + si->second;
        pair<ll, ll> p = make_pair(x, y);
        if(path[y][x] == '#') continue;
        // cout << x << " " << y << endl;
        if(x == gx && y == gy) {
          cout << i+1 << endl;
          return 0;
        } 
        if(past.find(p) == past.end()) {
          stage.insert(p);
          past.insert(p);
        }
      }
    }
  }
}

// int main(void) {
//   set<pair<ll,ll>> a;
//   a.insert(make_pair(1, 2));
//   set<pair<ll,ll>> b = a;
//   b.erase(make_pair(1, 2));
//   cout << (int)(a.find(make_pair(1, 2)) == a.end()) << endl;
//   cout << (int)(b.find(make_pair(1, 2)) == b.end()) << endl;
// }