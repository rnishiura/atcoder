#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(void) {
  ll N, W;
  cin >> N >> W;

  ll w, v, bw, bv;
  vector<pair<ll,ll>> DP;
  DP.push_back(make_pair(W+1, 0));

  for(ll i=0; i<N; i++) {
    cin >> v >> w;
    if (w > W) continue;
    sort(DP.rbegin(), DP.rend());

    // generate mater and pater
    vector<pair<ll,ll>> mater = DP;
    vector<pair<ll,ll>> pater;
    pater.push_back(make_pair(w, 0));
    for(auto dpitr = DP.rbegin(); dpitr != DP.rend(); ++dpitr) {
      bw = dpitr->first;
      bv = dpitr->second;
      if (bw+w <= W) {
        pater.push_back(make_pair(bw+w, bv+v));
      } else {
        pater.push_back(make_pair(W+1, bv+v));
        break;
      }
    }
    sort(pater.rbegin(), pater.rend());

    // generate shared weights
    set<ll> sw;
    for(auto itr=mater.begin(); itr != mater.end(); ++itr) sw.insert(itr->first);
    for(auto itr=pater.begin(); itr != pater.end(); ++itr) sw.insert(itr->first);

    // max alive baby
    DP.clear();
    auto mitr = mater.begin();
    auto pitr = pater.begin();
    ll mval, pval, prvmval, prvpval, winval, prvwinval = INT64_MAX;
    for(auto switr = sw.rbegin(); switr != sw.rend(); ++switr) {
      if (mitr == mater.end() || *switr > mitr->first) { 
        mval = prvmval; 
      } else {
        mval = mitr->second;
        prvmval = mval;
        ++mitr;
      } 
      if (pitr == pater.end() || *switr > pitr->first)  {
        pval = prvpval; 
      } else {
        pval = pitr->second;
        prvpval = pval;
        ++pitr;
      } 
      winval = max(pval, mval);
      if (prvwinval > winval) {
        DP.push_back(make_pair(*switr, winval));
        prvwinval = winval;
      }
    }
  }
  cout << DP[0].second << endl;
}
