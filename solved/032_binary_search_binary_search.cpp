#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(void) {
    ll N, X;
    cin >> N >> X;
    ll A[N];
    for(ll i=0; i<N; i++) cin >> A[i];
    sort(A, A+N);

    ll L=0, U=N-1;
    while(U > L+1) {
        ll M = (L+U)/2;
        if(A[M] < X) {
            L = M;
        } else {
            U = M;
        }
    }
    if (A[L] == X or A[U] == X) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}