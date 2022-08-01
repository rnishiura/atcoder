#include <bits/stdc++.h>
#define POW(N) ((N)*(N))
using ll = long long;
using namespace std;

bool rec(string S, ll N, auto& memo) {
  string sub1, sub2;
  bool a=false, b=false, c=false;
  if (N == 2) {
    if (S=="AA" || S=="BB") return true;
    else return false;
  }
  if (N == 3) {
    if (S[0]=='A' && S[1]=='B') return false;
    else return true;
  }
  if (S[0]=='B' && S[N-1]=='A') {
    sub1 = "B" + S.substr(2, N-3);
    sub2 = S.substr(1, N-3) + "A";
  }
  if (S[0]=='B' && S[N-1]=='B') {
    sub1 = S.substr(1, N-2);
    sub2 = S.substr(1, N-3) + "A";
  }
  if (S[0]=='A' && S[N-1]=='A') {
    sub1 = S.substr(1, N-2);
    sub2 = "B" + S.substr(2, N-3);
  }

  if (memo.find(sub1) != memo.end()) a = memo[sub1];
  else a = rec(sub1, N-2, memo);
  if (memo.find(sub2) != memo.end()) b = memo[sub2];
  else b = rec(sub2, N-2, memo);
  return a || b;
}

int main(void) {
  ll N;
  cin >> N;
  string S;
  cin >> S;
  map<string, bool> memo;
  if (rec(S, N, memo)) cout << "Yes" << endl;
  else cout << "No" << endl;
}


