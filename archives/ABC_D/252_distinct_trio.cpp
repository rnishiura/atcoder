#include <iostream>
#include <cmath>
using namespace std;

long map[200000];

int main(void) {
  int N;
  cin >> N;

  for(int i=0; i<200000; i++) map[i] = 0;
  int tmp;
  int num=0;
  for(int i=0; i<N; i++) {
    cin >> tmp;
    // cout << "tmp " << tmp << endl;
    // cout << "map[tmp] " << map[tmp] << endl;
    if(map[tmp] == 0) num++; 
    map[tmp]++;
  }
  long ccc = 1;
  for(int i=0; i<3; i++) ccc *= (num-i);
  for(int i=0; i<3; i++) ccc /= (i+1);

  cout << num << endl;
  cout << ccc << endl;

  for(int i=0; i<200000; i++) {
    if(map[i] != 0) ccc *= map[i];
  }

  for(int i=0; i<10; i++) {
    cout << map[i] << " ";
  }
  cout << endl;

  cout << ccc << endl;
  return 0;
}

