#include <bits/stdc++.h>
#define POW(N) ((N)*(N))
using ll = long long;
using namespace std;

void print(auto &v) {
  for(auto itr=v.begin(); itr!=v.end(); itr++) cout << *itr << " ";
  cout << endl;
}

int main(void) {
  ll N;
  string S, T;
  cin >> N >> S >> T;

  vector<ll> rsv, rtv;
  for(ll i=0; i<N; i++) {
    if(S[N-1-i] == '1') rsv.push_back(i);
    if(T[N-1-i] == '1') rtv.push_back(i);
  }
  if(rtv.size() > rsv.size()) {
    cout << "-1" << endl;
    return 0;
  }
  ll cnt=0;
  for(ll i=0; i<rtv.size(); i++) {
    if(rsv[i] <= rtv[i]) 
      cnt += rtv[i]-rsv[i];
    else {
      cout << "-1" << endl;
      return 0;
    }
  }
  if(rtv.size() == rsv.size()) {
    cout << cnt << endl;
    return 0;
  }
  if((rsv.size()-rtv.size()) % 2 == 1) {
    cout << "-1" << endl;
    return 0;
  }
  vector<ll> lsv;
  for(ll i=0; i<rsv.size()-rtv.size(); i++) {
    lsv.push_back(N-1-rsv[rsv.size()-1-i]);
  }
  ll b=lsv[0]+1;
  for(ll i=1; i<lsv.size(); i++) {
    cnt += lsv[i]-b++;
  }
  cnt += lsv.size() / 2;

  print(rsv);
  print(rtv);
  print(lsv);

  cout << cnt << endl;
}


// 5
// 10111
// 01010

// 10 10
// 01 10 
// 00 00
// 11 00

// 1は減らせど増やせない

// 0000001 1000000 01を左に進めば1を左に移動できる
// 0111111 1111110 01を右に進めば0を右に移動できる

// 0000110101
// 
