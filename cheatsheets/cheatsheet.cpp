#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <tuple>

using namespace std;

int main(void) {
  ////////////////// セット //////////////////////

  ////////////////// ペアクラス //////////////////////

  int n, m;
  cin >> n >> m;

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
  // cout << num << endl;

  return 0;

  ////////////////// tupleクラス //////////////////////
  tuple<int, int, int> t = make_tuple(2, 3, 2);
  cout << get<0>(t) << get<1>(t) << get<2>(t) << endl;
}
