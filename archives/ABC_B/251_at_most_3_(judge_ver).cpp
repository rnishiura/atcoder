#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
  int n, w;
  cin >> n;
  cin >> w;

  int l, a[n], i=0;

  while (cin >> l) {
    a[i] = l;
    i++;
    if(i >= n) break;
  }

  // int s1_len = n, s2_len = n*(n-1)/2, s3_len = n*(n-1)*(n-2)/3/2;
  // int s1[s1_len], s2[s2_len], s3[s3_len];

  bool flg[w+1];
  int tmp;

  for(int i=0; i<w+1; i++) flg[i] = false;

  // int cnt2 = 0, cnt3 = 0;
  for(int i=0; i<n; i++) {
    tmp = a[i];
    if(tmp > w) continue;
    flg[tmp] = true;

    for(int j=i+1; j<n; j++) {
      tmp = a[i] + a[j];
      if(tmp > w) continue;
      flg[tmp] = true;

      for(int k=j+1; k<n; k++) {
        tmp = a[i] + a[j] + a[k];
        if(tmp > w) continue;
        flg[tmp] = true;
      }
    }
  }

  int num = 0;
  for(int i=0; i<w+1; i++) { 
    if(flg[i]) num++;
  }

  // cout<<endl;
  // for(i=0; i<s1_len; i++) cout << s1[i] << endl;
  // cout<<endl;
  // for(i=0; i<s2_len; i++) cout << s2[i] << endl;
  // cout<<endl;
  // for(i=0; i<s3_len; i++) cout << s3[i] << endl;
  // cout<<endl;

  // int num = 0;
  // for(int i=0; i<s1_len; i++) if(s1[i]<=w) num++;
  // for(int i=0; i<s2_len; i++) if(s2[i]<=w) num++;
  // for(int i=0; i<s3_len; i++) if(s3[i]<=w) num++;

  cout << num << endl;
  // cout <<  << endl;

  return 0;
}


// #include <iostream>
// using namespace std;                        
// int main() { cout << "foo" << endl; return 0; }