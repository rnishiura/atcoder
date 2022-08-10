#include <bits/stdc++.h>
#define POW(z) ((z)*(z))
#define MOD 998244353
using namespace std;
using  ll = long long;
using   v = vector<ll>;

int main(void) {
  ll N, M;
  cin >> N >> M;

  // let's input'em
  v u(2);
  vector<set<ll>> vs(N+1);
  for(ll i=0; i<M; i++) {
    cin >> u[0] >> u[1];
    for(ll j=0; j<2; j++) vs[u[j]].insert(u[1-j]);
  }

  set<ll> past;
  set<ll> await;

  // start from...
  await.insert(1);
  while(await.size() > 0) {
    auto ni = await.begin();
    set<ll> d = vs[*ni];
    past.insert(*ni);
    await.erase(ni);

    // newly discovered, not past
    for(auto i=d.begin(); i!=d.end(); i++) {
      if (past.find(*i) == past.end()) {
        await.insert(*i);
      } 
    }
  }

  if(past.size() == N) {
    cout << "The graph is connected." << endl;
  } else {
    cout << "The graph is not connected." << endl;
  }
}
