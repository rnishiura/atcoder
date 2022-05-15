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
  int g[] = {3, 2, 4, 3, 2, 6};

  // ソート
  sort(g, g+l);
  for(int i=0; i<l; i++) cout << g[i] << endl;

  // 順列
  do {
    for(int i=0; i<l; i++) cout << g[i] << endl;
  } while( next_permutation(g, g+l) );

  // TODO 組み合わせ


  return 0;
}