#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

void append(long a, long ans);

int main() {
  long n;
  cin >> n;
  
  long a, b;
  for(long k=sqrt(n); k>1; k++){
    if(n%k == 0) {
      a = k;
      b = n/k;
      break;
    }
  }

  long ans[1000];

  int cnt = 0;
  long k=2;
  while(a > 1) {
    if(a%k == 0) {
      ans[cnt++] = k;
      a/=k;
      k=2;
    } else {
      k++;
    }
    if(k>sqrt(a)) {
      break;
    }
  }

  k=2;
  while(b > 1) {
    if(b%k == 0) {
      ans[cnt++] = k;
      b/=k;
      k=2;
    } else {
      k++;
    }
    if(k>sqrt(b)) {
      break;
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
