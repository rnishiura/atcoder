#include <bits/stdc++.h>
#define rep(x, n)      for(ll x=0; x<n; x++)
#define repi(x, a, b)  for(ll x=a; x<b; x++)
#define rrep(x, n)     for(ll x=n-1; x>=0; x--)
#define rrepi(x, a, b) for(ll x=b-1; x>=a; x--)
#define MOD 998244353
#define LL_MAX_S (1LL<<62)
#define DOUBLE_MAX_S ((double)LL_MAX_S)
#define print(z) cout << (z) << endl
#define print2(x, y) cout << x << " " << y << endl
#define square(z) ((z)*(z))
#define contains(x, s) (s.find(x) != s.end())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
using ll  = long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vp  = vector<pair<ll, ll>>;
using vvp = vector<vp>;

int main(void) {
  ll n;
  cin >> n;

  string s;
  unordered_set<string> m;
  unordered_set<char> s1{'H', 'D', 'C', 'S'};
  unordered_set<char> s2{'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
  rep(i, n) {
    cin >> s;
    if(contains(s[0], s1) && contains(s[1], s2)) {
      if(contains(s, m)) {
        print("No");
        return 0;
      }
      m.insert(s);
      continue;
    }
    print("No");
    return 0;
  }

  print("Yes");
  
}
