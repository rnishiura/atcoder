// https://atcoder.jp/contests/abc249/tasks/abc249_a
#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <utility>
#include <tuple>

using namespace std;

int main(void) {
  int A, B, C, D, E, F, X;
  cin >> A >> B >> C >> D >> E >> F >> X;

  int takahashi =  B * (A * (X / (A+C)) + min(X % (A+C), A) ) ;
  int aoki = E * (D * (X / (D+F)) + min(X % (D+F), D) );
  
  if (takahashi == aoki) {
    cout << "Draw";
  } else if (takahashi > aoki) {
    cout << "Takahashi";
  } else {
    cout << "Aoki";
  }
  cout << endl;
  return 0;
}