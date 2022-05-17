// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_s

#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

long longest = 0;

// TODO メモを追加

map<string, bool> memo;

void recurse(string str, long len, long gen) {
  longest = max(gen, longest);
  string substr;
  for( int pos=str.find("ARC"); pos != string::npos; pos = str.find("ARC", pos+1) ) {
    substr = str;
    if (gen % 2 == 0) {
      substr.replace(pos, 3, "R");
    } else {
      substr.replace(pos, 3, "AC");
    }
    // cout << substr << endl;
    if ( memo.find(substr) == memo.end() ) {
      cout << substr << endl;
      memo[substr] = true;
      recurse(substr, len-1, gen+1);
    } 
  }
}

int debug(void) {
  string str = "ARCARC";
  int pos=str.find("ARC", 1);
  cout << (pos != string::npos) << endl;

  str.replace(0, 3, "AC");

  cout << str << endl;
  return 0;
}

int release(void) {
  long n;
  string s;
  cin >> n >> s;

  recurse(s, n, 0);

  cout << longest << endl;
  return 0;
}

int main(void) {
  // return debug();
  release();

  // int i=0;
  // for (map<string, bool>::iterator itr = memo.begin(); itr != memo.end(); ++itr) {
  //   cout << itr->first << " ";
  //   i++;
  // }
  // cout << i << endl;

  // string s = "AARC";
  // string t = s;
  // t.replace(2, 2, "A");
  // cout << t << endl;
  // cout << s << endl;
}
