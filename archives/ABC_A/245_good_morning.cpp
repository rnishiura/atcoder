#include <iostream>
using namespace std;

int main(void) {
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  if(60*A+B <= 60*C+D) {
    cout << "Takahashi" << endl;
  } else {
    cout << "Aoki" << endl;
  }
}