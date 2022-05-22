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
  for(int i=0; i<N; i++) {
    cin >> s >> t;
    if(memo.find(s) == memo.end()) memo[s] = make_pair(t, i+1);
  }


  int max_i = -1;
  long max_t = 0;
  map< string, pair<long, int> >::iterator itr = memo.begin();
  for(; itr != memo.end(); itr++) {
    if (
      itr->second.first > max_t ||
      (itr->second.first == max_t && itr->second.second < max_i)
      ) {
      max_i = itr->second.second;
      max_t = itr->second.first; 
    }
  }

  cout << max_i << endl;
  
}