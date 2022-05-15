#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <tuple>

using namespace std;

int main(void) {
  ///////////////// 組み込み配列 ////////////////////

  int l = 6;
  int g[l] = {3, 2, 4, 3, 2, 6};

  // ソート
  sort(g, g+l);
  for(int i=0; i<l; i++) cout << g[i] << endl;

  // 順列
  do {
    for(int i=0; i<l; i++) cout << g[i] << endl;
  } while( next_permutation(g, g+l) )

  // TODO 組み合わせ


  return 0;

  ///////////////// 連想配列 ///////////////////////

  int n;
  cin >> n;

  string s[n]; int t[n];
  for(int i=0; i < n; i++) cin >> s[i] >> t[i];

  /** 連想配列 **/
  map<string, int> bools;

  // キーの探索及び代入
  for (int i=0; i<n; i++) {
    if ( bools.find(i) == bools.end() ) bools[i] = i*2; 
  }

  // イテレーション
  int max_i = 0;
  for (map<string, int>::iterator itr = bools.begin(); itr != bools.end(); ++itr) {
    if (t[itr->second] > t[max_i]) max_i = itr->second;
  }

  int num = max_i + 1;

  ////////////////// セット //////////////////////

  ////////////////// ペアクラス //////////////////////

  // int n, m;
  // cin >> n >> m;

  int a[m], b[m], c[m], d[m];
  for(int i=0; i < m; i++) cin >> a[i] >> b[i];
  for(int i=0; i < m; i++) cin >> c[i] >> d[i];

  // ペア配列の定義
  pair<int, int> ab[m], cd[m];

  // ペア生成
  for(int i=0; i<m; i++) {
    ab[i] = make_pair(a[i], b[i]);
    cd[i] = make_pair(c[i], d[i]);
  }

  sort(cd, cd+m);

  ////// 結果出力 //////
  cout << num << endl;

  return 0;

  ////////////////// tupleクラス //////////////////////
  tuple<int, int, int> t = make_tuple(2, 3, 2);
  cout << get<0>(t) << get<1>(t) << get<2>(t) << endl;
}
