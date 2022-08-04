#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(void) {
    ll N, K;
    cin >> N >> K;
    ll P[N];
    for(ll i=0; i<N; i++) cin >> P[i];
    ll S[N+1];
    for(ll i=0; i<N+1; i++) S[i] = -1; // 山のID
    // map<ll, ll> m; // ID to N
    // map<ll, ll> n; // ID to num 
    ll m[N+1], n[N+1];
    set<ll> face; // 山の表面のカード

    ll id=0;
    for(ll i=0; i<N; i++) {
        face.insert(P[i]);
        auto p = face.find(P[i]);
        // 新山
        if(p == --face.end()) {
            S[P[i]] = id++;
            n[S[P[i]]] = 1;
            m[S[P[i]]] = -1;
        } 
        // 既存
        else {
            S[P[i]] = S[*(++p)];
            n[S[P[i]]]++;
            face.erase(*p);
        }
        // K以上
        if(n[S[P[i]]] >= K) {
            m[S[P[i]]] = i+1;
            face.erase(P[i]);
        }
    }

    for(ll i=1; i<N+1; i++) {
        cout << m[S[i]] << endl;
    }
}