#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int test(map<ll, ll> *memo) {
    cout << memo << endl;
    cout << (*memo)[0] << endl; 
    (*memo)[1] = 2;
    return 0;
}

int main() {
    map<ll, ll> memo;
    cout << &memo << endl;
    memo[0] = 2;
    test(&memo);
    cout << memo[1] << endl; 
    return 0;
} 
