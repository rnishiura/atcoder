#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

void recursive_fact(long a, long ans) {
  
}

int main() {
  long n;
  cin >> n;
  
  long a = n;
  long cnt = 0;
  long k=2;
  long ans[1000];

  while(a > 1) {
    if(a%k == 0) {
      ans[cnt++] = k;
      a/=k;
      k=2;
    } else {
      k++;
    }
  }

  sort(ans, ans+cnt);
 
  for(int i=0; i < cnt; i++) {
    cout << ans[i] << " ";
  }
  // for(map<int, long>::iterator itr = ans.begin(); itr != ans.end(); itr++) {
  //   cout << itr->first << " ";
  // }
  cout << endl;

  return 0;
}
