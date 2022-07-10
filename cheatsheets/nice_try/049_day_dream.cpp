#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string token[] = {"dream","dreamer","erase","eraser"};

map<string, bool> memo;

bool parse(string S) {
  if (S.length() == 0) return true;
  bool ret = false;
  for(ll i=0; i<4; i++) {
    if(S.substr(0, token[i].length()) == token[i]) {
      string subs = S.substr(token[i].length());
      bool subr;
      if(memo.find(subs) == memo.end()) {
        subr = parse(subs);
        memo[subs] = subr;
      } else {
        subr = memo[subs];
      }
      ret = ret || subr;
    }
  } 
  return ret;
}

int main(void) {
  string S;
  cin >> S;

  if (parse(S)) cout << "YES" << endl;
  else cout << "NO" << endl;

  // for(auto itr = memo.begin(); itr != memo.end(); itr++) {
  //   cout << itr->first << " " << itr->second << endl;
  // }
}

