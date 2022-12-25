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

  ll A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;

  vp note;
  ll x, y;
  for(ll i=0; i<M; i++) {
    cin >> x >> y;
    note.push_back(make_pair(x, y));
  }

  ll cnt, p, q, r, rc, rm, qc, qm;

  for(ll n=1; n<=N; n++) {
    ll cnt=0;
    for(auto item: note) {
      x = item.first; y = item.second;
      rc = (x-n*A)*(D-B) - (y-n*B)*(C-A);
      rm = (E-A)*(D-B) - (F-B)*(C-A);

      if(!rm or (rc+rm)%rm or rc/rm<0) continue;
      r = rc/rm;
      qc = (x-n*A)*(F-B) - (y-n*B)*(E-A);
      qm = (C-A)*(F-B) - (D-B)*(E-A);

      if(!qm or (qc+qm)%qm or qc/qm<0) continue;
      q = qc/qm;
      p = n-q-r;

      if(p<0) continue;
      cnt++;
    } 
    cout << cnt << endl;
  }

}
