#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void extend(auto in, auto &out, auto sw) {
  auto dpitr = in.begin();
  for(auto itr=sw.rbegin(); itr != sw.rend(); ++itr) {
    if (dpitr == in.end() or *itr > dpitr->first) {
      out.push_back(make_pair(*itr, out.rbegin()->second));
    } else {
      out.push_back(make_pair(*itr, dpitr->second));
      ++dpitr;
    }
  }
}

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
    for(auto itr=DP.rbegin(); itr != DP.rend(); ++itr) {
      bw = itr->first;
      bv = itr->second;
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
    
    // extend pater mater
    vector<pair<ll,ll>> exmater, expater;
    extend(mater, exmater, sw);
    extend(pater, expater, sw);

    // max alive baby
    // vector<pair<ll,ll>> baby;
    DP.clear();
    auto mitr = exmater.begin();
    auto pitr = expater.begin();
    ll prevval = INT64_MAX;
    ll winval;
    while(mitr != exmater.end()) {
      winval = max(mitr->second, pitr->second);
      if (prevval > winval) {
        DP.push_back(make_pair(mitr->first, winval));
        prevval = winval;
      }
      ++mitr;
      ++pitr;
    }

    // renew DP
    // DP = baby;
  }
  cout << DP[0].second << endl;
}
