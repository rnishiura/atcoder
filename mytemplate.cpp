// https://atcoder.jp/contests/abc251/tasks/abc251_b

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

  ////// 問題入力 //////
  int n, w;
  cin >> n; cin >> w;

  int l, i=0, a[n];
  while (cin >> l) {
    a[i] = l;
    i++;
    if(i >= n) break;
  }

  ////////////////////////////////////////

  bool flg[w+1];
  int tmp;

  for(int i=0; i<w+1; i++) flg[i] = false;

  for(int i=0; i<n; i++) {
    tmp = a[i];
    if(tmp > w) continue;
    flg[tmp] = true;

    for(int j=i+1; j<n; j++) {
      tmp = a[i] + a[j];
      if(tmp > w) continue;
      flg[tmp] = true;

      for(int k=j+1; k<n; k++) {
        tmp = a[i] + a[j] + a[k];
        if(tmp > w) continue;
        flg[tmp] = true;
      }
    }
  }

  int num = 0;
  for(int i=0; i<w+1; i++) { 
    if(flg[i]) num++;
  }

  ////////////////////////////////////////

  ////// 結果出力 //////
  cout << num << endl;

  return 0;
}