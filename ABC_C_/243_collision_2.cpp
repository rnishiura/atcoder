#include <iostream>
#include <cmath>
#include <map>
#include <utility>
#include <vector>
using namespace std;

int main(void) {
  int N;
  cin >> N;

  int X[N], Y[N];
  for(int i=0; i<N; i++) cin >> X[i] >> Y[i];

  string s;
  cin >> s;

  map< int, vector< pair<int, char> > > X_CH;

  for(int i=0; i<N; i++) {
    if(X_CH.find(Y[i]) == X_CH.end()) {
      vector< pair<int, char> > v;
      X_CH[Y[i]] = v;
    }
    X_CH[Y[i]].push_back(make_pair(X[i], s[i]));
  }
  
  map< int, vector< pair<int, char> > >::iterator itr = X_CH.begin();
  for(itr = X_CH.begin(); itr != X_CH.end(); itr++) {
    cout << itr->second[0].first << endl;
  }
  
  cout << N << endl;
  return 0;
}

