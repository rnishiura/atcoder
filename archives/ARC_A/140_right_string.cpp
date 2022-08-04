// TODO permutationが遅すぎる

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <tuple>

using namespace std;

string op(string s, int n) {
  return s.substr(1, n-1) + s[0];
}

int f(string s, int n) {
  map<string, bool> counter;
  for(int i=0; i<n; i++) {
    if(counter.find(s) == counter.end()) counter[s] = true;

    s=op(s, n);
  }
  int num = 0;
  for(map<string, bool>::iterator itr = counter.begin(); itr != counter.end(); ++itr) {
    num++;
  }
  return num;
}

int main(void) {
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  int min_f = n;
  int indice[n];
  for(int i=0; i<n; i++) indice[i] = i;

  // map<int[], int> comb;
  int som;
  do {
    string tmp = s;
    for(char c='a'; c<='z'; c++) {
      for(int i=0; i<k; i++) {
          tmp[indice[i]] = c;
      }
      // cout << tmp << endl;
      // 
      // min_f = min(min_f, f(tmp, n));
      som = f(tmp, n);
      if(som  < min_f) {
        cout << tmp << endl;
        cout << som << endl;
        min_f = som;
      }
    }
  } while(next_permutation(indice, indice+n));

  cout << min_f << endl;

  return 0;
}

