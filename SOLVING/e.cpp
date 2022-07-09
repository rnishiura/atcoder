#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void print_vpll(auto vpll) {
  for(auto itr = vpll.begin(); itr != vpll.end(); ++itr) {
    cout << itr->first << " " << itr->second << endl;
  }
}
int main(void) {
  vector<pair<ll,ll>> DP;
  DP.push_back(make_pair(2,3));
  DP.push_back(make_pair(3,2));
  DP.push_back(make_pair(1,2));
  print_vpll(DP);
  sort(DP.rbegin(), DP.rend());
  print_vpll(DP);
}
