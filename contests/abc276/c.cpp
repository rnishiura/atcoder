#include <bits/stdc++.h>
#define rep(x, n)      for(ll x=0; x<n; x++)
#define repi(x, a, b)  for(ll x=a; x<b; x++)
#define rrep(x, n)     for(ll x=n-1; x>=0; x--)
#define rrepi(x, a, b) for(ll x=b-1; x>=a; x--)
#define contains(x, s) (s.find(x) != s.end())
#define square(z) ((z)*(z))
#define MOD 998244353
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define print(z) cout << (z) << endl
#define print2(x, y) cout << x << " " << y << endl
using namespace std;
using ll  = long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vp  = vector<pair<ll, ll>>;
using vvp = vector<vp>;

int main(void) {
  ll N;
  cin >> N;

  v A(N);
  rep(i, N) {
    cin >> A[i];
  }

  prev_permutation(A.begin(), A.end());

  for(auto v: A) {
    cout << v << " ";
  }
  cout << endl;
}