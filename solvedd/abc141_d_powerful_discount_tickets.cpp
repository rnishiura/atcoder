#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
    ll N, M;
    cin >> N >> M;
    multiset<ll> ms;
    ll tmp;
    for(ll i=0; i<N; i++) {
        cin >> tmp;
        ms.insert(tmp);
    }
    ll t=0;
    multiset<ll>::iterator it;
    for(ll i=0; i<M; i++) {
        it = ms.end();
        ms.erase(--it);
        ms.insert(*it / 2);
    }
    for(it=ms.begin(); it != ms.end(); it++) {
        t += *it;
    }
    cout << t << endl;
}