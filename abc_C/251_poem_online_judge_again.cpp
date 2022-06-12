#include <iostream>
#include <map>
#include <utility>
using namespace std;

int main(void) { 
  int N;
  cin >> N;

  map< string, pair<long, int> > memo;

  string s;
  long t;

  string itr[N];
  int cnt = 0;
  for(int i=0; i<N; i++) {
    cin >> s >> t;
    if(memo.find(s) == memo.end()) {
      memo[s] = make_pair(t, i+1);
      itr[cnt++] = s;
    }
  }

  int max_i = -1;
  long max_t = 0;

  for(int i=0; i<cnt; i++) {
    if (memo[itr[i]].first > max_t) {
      max_i = memo[itr[i]].second;
      max_t = memo[itr[i]].first; 
    }
  }

  cout << max_i << endl;
  
}