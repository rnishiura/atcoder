#include <iostream>
#include <cmath>
using namespace std;

// nの約数

int main() {
    long n;
    cin >> n;

    cout << 1 << endl; if (n == 1) return 0;

    // 平方根以下の探索; そしてその対
    for (long i=sqrt(n); i>=1; i--) {

        if(i == 1) {
            cout << n << endl;
            return 0;
        }

        if (n%i == 0) {
            cout << i << endl;

            if (i == n/i) continue;
            cout << n/i << endl;
        }
    }

    return 0;
}
