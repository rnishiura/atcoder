#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
    ll N;
    cin >> N;
    ll A[N], B[N];
    for(ll i=0; i<N; i++) {
        cin >> A[i] >> B[i];
        B[i] += A[i];
    }

    sort(A, A+N);
    sort(B, B+N);

    ll i=1, j=0, cnt=1;
    ll p = A[0];
    ll C[N+1];
    for(ll i=1; i<=N; i++) C[i] = 0;

    while(i<N) {
        if(A[i] < B[j]) {
            C[cnt] += A[i] - p;
            p = A[i];
            i++;
            cnt++;
        }
        if(A[i] > B[j]) {
            C[cnt] += B[j] - p;
            p = B[j];
            j++;
            cnt--;
        } 
        if(A[i] == B[j]) {
            C[cnt] += B[j] - p;
            p = B[j];
            j++;
            i++;
        }      
    }
    while(j<N) {
        C[cnt] += B[j] - p;
        p = B[j];
        j++;
        cnt--;
    }

    for(ll i=1; i<=N; i++) {
        cout << C[i] << " ";
    }
    cout << endl;
}