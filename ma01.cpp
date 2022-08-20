#include <iostream>
#include <string>
#include <list>
using namespace std;
using ll = long long;

int main(int argc, char *argv[]) {
  ll N; cin >> N;

  ll q, a, b, cnt=0;
  
  multiset<ll> A, B;
  A.insert(0);
  B.insert(0);

  ll best_a, best_b, worst_a, worst_b;

  for(ll i=0; i<N; i++) {
    cin >> q;
    switch(q) {
      case 1:
      cin >> a >> b;
      best_a = *A.begin();
      best_b = *B.begin();
      worst_a = *(--A.end());
      worst_b = *(--B.end());

      if(a >= best_a and b >= best_b) {
        A.clear(); A.insert(a);
        B.clear(); B.insert(b);
        cnt = 1;
      } else if (a <= worst_a and b <= worst_b) {
      } else {
        A.insert(a);
        B.insert(b);
        cnt++;
      }
      break;

      case 2:
      cout << cnt << endl;
      break;
    }
  }

  return 0;
}
