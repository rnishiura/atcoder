// https://atcoder.jp/contests/abc251/tasks/abc251_c

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void) {

  ////// 問題入力 //////
  int n;
  cin >> n;

  string s[n]; int t[n];
  for(int i=0; i < n; i++) cin >> s[i] >> t[i];

  ////////////////////////////////////////

  map<string, int> bools;

  for (int i=0; i<n; i++) {
    if ( bools.find(s[i]) == bools.end() ) bools[s[i]] = i; 
  }

  int max_i = 0;
  for (map<string, int>::iterator itr = bools.begin(); itr != bools.end(); ++itr) {
    if (t[itr->second] > t[max_i]) max_i = itr->second;
  }

  int num = max_i + 1;
  ////////////////////////////////////////

  ////// 結果出力 //////
  cout << num << endl;

  return 0;
}
