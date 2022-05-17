#include <iostream>
using namespace std;

int main(void) {
  int N, A, B;
  cin >> N >> A >> B;

  for(int i=0; i<A*N; i++) {
    for(int j=0; j<B*N; j++) {
      if ( ( (i/A)%2 + (j/B)%2 ) % 2 == 0 ) {
        cout << ".";
      }
      else {
        cout << "#";
      }
    }
    cout << endl;
  }
}