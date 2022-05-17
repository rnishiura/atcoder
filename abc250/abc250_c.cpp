#include <iostream>
using namespace std;

int main(void) {

  long N, Q;
  cin >> N >> Q;

  long btoi[N], itob[N];

  for(long i=0; i<N; i++) {
    btoi[i] = i;
    itob[i] = i;
  }

  long a, i, adj_i, b, adj;
  for(long c=0; c<Q; c++) {
    cin >> a;
    a--;
    i = btoi[a];
    adj_i = i == N-1 ? i-1 : i+1;
    adj = itob[adj_i];
    itob[i] = adj;
    itob[adj_i] = a;
    btoi[a] = adj_i;
    btoi[adj] = i;
  }

  for(long i = 0; i<N; i++) {
    cout << itob[i]+1 << " ";
  }
  cout << endl;

  return 0;
}