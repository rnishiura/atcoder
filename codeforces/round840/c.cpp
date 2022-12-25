#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define MOD 998244353
#define LL_MAX_S  (1LL<<62)
#define DBL_MAX_S ((double)LL_MAX_S)
#define rep(x, n)      for(ll x=0; x<n; x++)
#define repi(x, a, b)  for(ll x=a; x<b; x++)
#define rrep(x, n)     for(ll x=n-1; x>=0; x--)
#define rrepi(x, a, b) for(ll x=b-1; x>=a; x--)
#define square(z) ((z)*(z))
#define contains(x, a) ((a).find(x) != (a).end())
#define all(x) (x).begin(), (x).end()
#define maxi(a) (max_element(all(a)) - (a).begin())
#define mini(a) (min_element(all(a)) - (a).begin())
#define maxe(a) (*max_element(all(a)))
#define maxe(a) (*min_element(all(a)))
#define lowb(a, x) (*lower_bound(all(a), (x)) - (a).begin())
#define uppb(a, x) (*upper_bound(all(a), (x)) - (a).begin())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define unordered_multiset multiset
#define unordered_set set
#define unordered_map map
#define divl(n, m)  ((n+m)/(m)) 
#define divle(n, m) ((n+m-1)/(m)) 
#define divse(n, m) ((n)/(m)) 
#define divs(n, m)  ((n-1)/(m)) 
#define endl '\n'
#define printr(z)       cout << (z) << ' '
#define println()       cout << endl
#define print(z)        cout << (z) << endl
#define print2(y, z)    cout << (y) << ' '; print(z)
#define print3(x, y, z) cout << (x) << ' '; print2(y, z)
using namespace std;
using ll  = long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vp  = vector<pair<ll, ll>>;
using vvp = vector<vp>;

void solve() {
  ll n; cin >> n;
  ll sum = 0;
  v a(n); rep(i, n)  {
    cin >> a[i]; 
    sum += a[i];
  }

  ll max_val;
  if(n == 2) {
    print(max(llabs(a[0]-a[1])*2, sum));
    return;
  }
  if(n == 3) {
    max_val = sum;
    max_val = max(max_val, a[0]*3);
    max_val = max(max_val, a[2]*3);
    max_val = max(max_val, llabs(a[0]-a[1])*2+a[2]);
    max_val = max(max_val, llabs(a[2]-a[1])*2+a[0]);
    max_val = max(max_val, llabs(a[0]-a[1])+2*llabs(llabs(a[0]-a[1])-a[2]));
    max_val = max(max_val, llabs(a[2]-a[1])+2*llabs(llabs(a[2]-a[1])-a[0]));
    max_val = max(max_val, llabs(a[0]-a[1])*3);
    max_val = max(max_val, llabs(a[2]-a[1])*3);
    max_val = max(max_val, 3*llabs(llabs(a[0]-a[1])-a[2]));
    max_val = max(max_val, 3*llabs(llabs(a[2]-a[1])-a[0]));
    print(max_val);
    return;
  }
  
  max_val=sum;
  rep(i, n) {
    // if(i == 1 || i == n-2) continue;
    max_val = max(max_val, a[i]*n);
  }
  // max_val = max(max_val, max(a[1]*(n-2)+2*llabs(a[1]-a[0]), a[1]*(n-1)+a[0]));
  // max_val = max(max_val, max(a[n-2]*(n-2)+2*llabs(a[n-1]-a[n-2]), a[n-2]*(n-1)+a[n-1]));
  print(max_val);
}

int main(void) {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  ll t = 1; cin >> t;
  rep(i, t) solve();
}
