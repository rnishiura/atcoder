#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string identify(ll y, ll x, ll* pY, ll* pX, ll* qY, ll* qX, ll K) {
  string ret = "";
  double dtheta;
  for(ll i=0; i<K; i++) {
    dtheta = fmod(atan2(qY[i]-pY[i], qX[i]-pX[i]) - atan2(y-pY[i], x-pX[i]) + 6*M_PI, 2*M_PI);
    // dtheta = atan2(qY[i]-pY[i], qX[i]-pX[i]) - atan2(y-pY[i], x-pX[i]);
    if(dtheta == 0 || dtheta == M_PI) 
      ret += "2";
    else if(dtheta < M_PI)
      ret += "1";
    else
      ret += "0";
  }
  // if (x==-2504 && y==1025) cout << " " << ret << endl;
  // if (x==-2297 && y==801) cout << " " << ret << endl;
  // if (ret == "0122") cout << "hi" << endl;
  return ret;
}

int score(ll *A, ll* B) {
  int ret = 0;
  for(ll i=1; i<=10; i++) {
    ret += min(A[i], B[i]);
  }
  return ret;
}

int main(void) {
  ll N, K;
  cin >> N >> K;

  srand(0);

  ll A[10+1];
  for(ll i=1; i<=10; i++) {
    cin >> A[i];
  }

  ll X[N+1], Y[N+1];
  for(ll i=1; i<=N; i++) {
    cin >> X[i] >> Y[i];
  }

  ll L = K;
  L = 100;

  // cout << L << endl;
  ll pX[L], pY[L], qX[L], qY[L];
  ll _pX[L], _pY[L], _qX[L], _qY[L];
  ll _score = 0, new_score;
  ll MAX_REPEAT = 250000;
  for(ll i=0; i<max(1, int(MAX_REPEAT / N)); i++) {
    for(ll i=0; i<L; i++) {
      pX[i] = rand() % 10000 - 5000;
      pY[i] = rand() % 10000 - 5000;
      qX[i] = rand() % 10000 - 5000;
      qY[i] = rand() % 10000 - 5000;
      // cout << pX[i] << " " << pY[i] << " " << qX[i] << " " << qY[i] << endl;
    }

    map<string, int> id;
    string identifier;
    for(ll i=1; i<=N; i++) {
      identifier = identify(Y[i], X[i], pY, pX, qY, qX, L);

      if (id.find(identifier) == id.end()) id[identifier] = 1;
      else id[identifier] += 1;
    }
    ll B[10+1]; for(ll i=0; i<=10; i++) B[i] = 0;
    for(auto itr = id.begin(); itr != id.end(); itr++) {
      if(1 <= itr->second && itr->second <= 10) {
        // cout << itr->first << " " << itr->second << endl;
        B[itr->second] += 1;
      }
    }

    new_score = score(A, B);
    // cout << "score: " << new_score << endl;
    if(new_score > _score) {
      _score = new_score;
      for(ll i=0; i<L; i++) {
        _pX[i] = pX[i];
        _pY[i] = pY[i];
        _qX[i] = qX[i];
        _qY[i] = qY[i];
      }
    }
  }

  // for(ll i=1; i<=10; i++) cout << B[i] << " ";
  // cout << endl;  

  cout << L << endl;
  for(ll i=0; i<L; i++) {
    cout << _pX[i] << " " << _pY[i] << " " << _qX[i] << " " << _qY[i] << endl;
  }
  // cout << _score << endl;
  return 0;
}

