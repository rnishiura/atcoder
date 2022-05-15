#include <iostream>
using namespace std;

int main(void) {
  cout << min(3, 5) << endl;
  return 0;

  int n, w;
  cin >> n >> w;

  int a[n];
  for (int i=0; i<n; i++) cin >> a[i];

  bool flg[w+1];
  for (int i=0; i<=w; i++) flg[i] = false;

  int tmp;
  for (int i=0; i<n; i++) {
    tmp = a[i];
    if (tmp > w) continue;
    flg[tmp] = true;

    for (int j=i+1; j<n; j++){
      tmp = a[i] + a[j];
      if (tmp > w) continue;
      flg[tmp] = true;

      for (int k=j+1; k<n; k++){
        tmp = a[i] + a[j] + a[k];
        if (tmp > w) continue;
        flg[tmp] = true;
      }
    }
  }

  int num = 0;
  for (int i=0; i<=w; i++) if (flg[i]) num++;

  cout << num << endl;
}