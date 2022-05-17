// https://atcoder.jp/contests/abc249/tasks/abc249_b

#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <utility>
#include <tuple>
#include <map>

using namespace std;


int main(void) {
  string s;
  cin >> s;

  // cout << s.length() << endl;
  map<char, bool> memo;
  bool A = false, a = false;

  for(int i=0; i < s.length(); i++) {
    if (memo.find(s[i]) == memo.end()) {
      memo[s[i]] = true;
    } else {
      cout << "No" << endl;
      return 0;
    }
    if('a' <= s[i] && s[i] <= 'z') a = true;
    if('A' <= s[i] && s[i] <= 'Z') A = true;
  }
  if(a == false || A == false) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}