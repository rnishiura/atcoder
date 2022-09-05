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

void print_v(auto a) {
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

  deque<ll> A(N);
  for(ll i=0; i<N; i++) cin >> A[i];
  sort(A.begin(), A.end());

  ll f, b;
  ll cnt = 0;
  while(N > 1) {
    b = A.back();
    f = A.front();
    A.pop_back();
    if (b%f) {
      A.push_front(b%f);
    } else {
      N--;
    }
    cnt++;
    // print_v(A);
  }
  cout << cnt << endl;
}
