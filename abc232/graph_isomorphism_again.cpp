#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main(void) {

  int N, M;
  cin >> N >> M;

  pair<int, int> str_AB[M], str_CD[M], str_CD_repl[M];

  int a, b;
  for(int i=0; i<M; i++) {
    cin >> a >> b;
    str_AB[i] = make_pair(a, b);
  }

  for(int i=0; i<M; i++) {
    cin >> a >> b;
    str_CD[i] = make_pair(a, b);
  }

  int labels[N];
  for(int i=0; i<N; i++) {
    labels[i] = i+1;
  }

  sort(str_AB, str_AB + M);

  do {

    for(int i=0; i<M; i++) {
      int _min = min(labels[str_CD[i].first-1], labels[str_CD[i].second-1]);
      int _max = max(labels[str_CD[i].first-1], labels[str_CD[i].second-1]);
      str_CD_repl[i] = make_pair(_min, _max);
    }

    sort(str_CD_repl, str_CD_repl + M);

    bool flg = true;

    for(int i=0; i<M; i++) {
      if (str_AB[i] != str_CD_repl[i]) {
        flg = false;
        break;
      }
    }

    if (flg) {
      cout << "Yes" << endl;
      return 0;
    }
  } while( next_permutation(labels, labels+N) );

  cout << "No" << endl;

  return 0;
}