// https://atcoder.jp/contests/math-and-algorithm/tasks/math_and_algorithm_s

#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int release(void) {
  long n; 
  cin >> n;

  int a[n];
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }

  long num=0;
  for(int i=0; i<n-4; i++) 
    for(int j=i+1; j<n-3; j++) 
      for(int k=j+1; k<n-2; k++)
        for(int l=k+1; l<n-1; l++) 
          for(int m=l+1; m<n-0; m++)
            if(a[i]+a[j]+a[k]+a[l]+a[m]==1000) num++;

  cout << num << endl;

  return 0;
}

int main(void) {
  // return debug();
  return release();
}