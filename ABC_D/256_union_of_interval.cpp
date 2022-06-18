#include <bits/stdc++.h>
#define MAX 200001
using ll = long long;
using namespace std;

int main(void) {
  ll N;
  cin >> N;
  
  ll l, r;
  
  ll LEFT[MAX], RIGHT[MAX];
  for(int i=0; i<MAX; i++) {
    LEFT[i] = 0;
    RIGHT[i] = 0;
  }
  for(int i=0; i<N; i++) {
    cin >> l >> r;
    LEFT[l] += 1;
    RIGHT[r] += 1;
  }
  ll stk = 0;
  ll cnt = 0;
  ll left, right;
  vector< pair<int, int> > s;

  // for(int i=0; i<50; i++) {
  //   cout << LEFT[i] << " " << RIGHT[i] << endl;
  // }
  for(int i=0; i<MAX; i++) {
    if(stk == 0 && LEFT[i] > 0) {
      // 左界発見！
      left = i;
      // cout << left << endl;
    }
    stk += LEFT[i];
    if(stk > 0 && stk - RIGHT[i] == 0 && LEFT[i] == 0) {
      // 右界発見！
      right = i;
      // cout << right << endl;
      s.push_back(make_pair(left, right));
    }
    stk -= RIGHT[i];
    // cout << i << " " << stk << endl;
  }

  for(auto itr=s.begin(); itr!=s.end(); itr++) {
    cout << (*itr).first << " " << (*itr).second << endl;
  }
}
