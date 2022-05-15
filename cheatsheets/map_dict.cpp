/* 例題：ポエムオンラインジャッジ(POJ)問題 */
///////////////// 連想配列 ///////////////////////

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <tuple>

using namespace std;

int main(void) {

  int n;
  cin >> n;

  string s[n]; int t[n];
  for(int i=0; i < n; i++) cin >> s[i] >> t[i];

  /** 連想配列 **/
  map<string, int> bools;

  // キーの探索及び代入
  for (int i=0; i<n; i++) {
    if ( bools.find(s[i]) == bools.end() ) bools[s[i]] = t[i]; 
  }

  // イテレーション
  int max_i = 0;
  for (map<string, int>::iterator itr = bools.begin(); itr != bools.end(); ++itr) {
    if (t[itr->second] > t[max_i]) max_i = itr->second;
  }

  int num = max_i + 1;

  cout << num << endl;
}