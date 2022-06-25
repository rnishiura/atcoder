#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main(void) {
  ll N;
  cin >> N;
  string S;
  cin >> S;
  multiset<ll> chW, adW;
  ll W;
  ll chLen = 0, adLen = 0;
  for(ll i=0; i<N; i++) {
    cin >> W;
    if ('0' == S[i]) {
      chW.insert(W);
      chLen += 1;
    }
    if ('1' == S[i]) {
      adW.insert(W);
      adLen += 1;
    }
  }
  ll err = chLen;
  ll besterr = err;
  auto aditr = adW.begin();
  for(auto chitr = chW.begin(); chitr != chW.end(); ) {
    ll idx = *(chitr);
    ll chcnt = 0;
    for(; chitr != chW.end(); chcnt++) {
      if (*(chitr)>idx) {
        break;
      }
      chitr++;
    }
    ll adcnt = 0;
    for(; aditr != adW.end(); adcnt++) {
      if (*(aditr)>idx) {
        break;
      }
      aditr++;
    }
    // cout << adcnt << endl;
    // cout << chcnt << endl;
    err += adcnt - chcnt;
    besterr = min(besterr, err);
  }
  // cout << endl;
  // cout << adLen << endl;
  // cout << chLen << endl;
  // cout << besterr << endl;
  cout << adLen + chLen - besterr << endl;
}
