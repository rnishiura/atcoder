#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string identify(ll y, ll x, ll* pY, ll* pX, ll* qY, ll* qX, ll K) {
  string ret = "";
  double dtheta;
  for(ll i=0; i<K; i++) {
    // dtheta = fmod(atan2(qY[i]-pY[i], qX[i]-pX[i]) - atan2(y-pY[i], x-pX[i]) + 6*M_PI, 2*M_PI);
    cout << atan2(qY[i]-pY[i], qX[i]-pX[i]) << " " << atan2(y-pY[i], x-pX[i]) << " ";
    dtheta = atan2(qY[i]-pY[i], qX[i]-pX[i]) - atan2(y-pY[i], x-pX[i]);
    cout << dtheta << endl;
    if(dtheta == 0 || dtheta == M_PI) 
      ret += "2";
    else if(dtheta < M_PI)
      ret += "1";
    else
      ret += "0";
  }
  if (x==-2504 && y==1025) cout << " " << ret << endl;
  if (x==-2297 && y==801) cout << " " << ret << endl;
  return ret;
}

int main(void) {
  cout << fmod(-0.2+7*M_PI, M_PI) << endl;
  ll pX[4], pY[4], qX[4], qY[4];
  for(ll i=0; i<4; i++) {
    cin >> pX[i] >> pY[i] >> qX[i] >> qY[i];
  }
  ll x1 = -2504, y1 = 1025;
  ll x2 = -2297, y2 = 801;
  cout << identify(y1, x1, pY, pX, qY, qX, 4) << endl;
  cout << identify(y2, x2, pY, pX, qY, qX, 4) << endl;
}

