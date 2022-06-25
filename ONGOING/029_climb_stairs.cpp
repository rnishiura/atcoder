#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll nums(ll n, map<ll, ll> *memo) {
    if ( (*memo).find(n) != (*memo).end() ){
        return (*memo)[n];
    }
    if (n==1) {
        return 1;
    }
    if (n==0) {
        return 1;
    }
    ll ret = nums(n-1, memo) + nums(n-2, memo);
    (*memo)[n] = ret;
    return ret;
}

int main() {
    ll N;
    cin >> N;
    map<ll, ll> memo;
    
    cout << nums(N, &memo) << endl;
    return 0;
} 
