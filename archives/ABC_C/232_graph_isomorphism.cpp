// https://atcoder.jp/contests/abc251/tasks/abc251_b

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(void) {

  ////// 問題入力 //////
  int n, m;
  cin >> n >> m;

  int a[m], b[m], c[m], d[m];
  for(int i=0; i < m; i++) cin >> a[i] >> b[i];
  for(int i=0; i < m; i++) cin >> c[i] >> d[i];

  ////////////////////////////////////////

  pair<int, int> ab[m], cd[m];

  for(int i=0; i<m; i++) {
    ab[i] = make_pair(a[i], b[i]);
    cd[i] = make_pair(c[i], d[i]);
  }

  sort(cd, cd+m);

  // for(int i=0; i<m; i++) {
  //   cout << '(' << cd[i].first << ',' << cd[i].second << "),";
  // }

  int map[n]; 
  for (int i=0; i<n; i++) map[i] = i+1;
  pair<int, int> tmp[m];
  int p, q;
  do {
    // for(int i=0; i<n; i++) cout << map[i] << " ";
    // cout << endl;
    
    for(int i=0; i<m; i++) {
      p = map[ ab[i].first -1 ];
      q = map[ ab[i].second-1 ];
      tmp[i].first  = min(p, q);
      tmp[i].second = max(p, q);
    }

    sort(tmp, tmp+m);


    // for(int i=0; i<m; i++) {
    //   cout << '(' << tmp[i].first << ',' << tmp[i].second << "),";
    // }
    // cout << endl;

    bool flg = true;
    for(int i=0; i<m; i++) {
      if(tmp[i] != cd[i]) {
        flg = false;
        break;
      }
      // cout << "hi";
    }

    if (flg == true) {
      cout << "Yes" << endl;
      return 0;
    }
  } while (next_permutation(map, map+n));

  cout << "No" << endl;



  ////////////////////////////////////////

  ////// 結果出力 //////
  // cout << num << endl;

  return 0;
}