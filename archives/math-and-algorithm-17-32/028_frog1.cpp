#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cnt=0;

int min_cost(ll i, ll* h, map<ll, ll> *memo) {
    cnt++;
    if((*memo).find(i) != (*memo).end()) {
        // cout << "memo" << endl;
        return (*memo)[i];
    }
    
    if(i==1) {
        return abs(h[i]-h[i-1]);
    } else if(i==0) {
        return 0;
    } else {
        ll d1 = abs(h[i]-h[i-1]) + min_cost(i-1, h, memo);
        ll d2 = abs(h[i]-h[i-2]) + min_cost(i-2, h, memo);
        ll ret = min(d1, d2);
        (*memo)[i] = ret;
        return ret;
    }
}

int main() {
    ll N;
    cin >> N;
    ll h[N];
    for(ll i=0; i<N; i++) {
        cin >> h[i];
    }
    map<ll, ll> memo;
    
    cout << min_cost(N-1, h, &memo) << endl;
    // cout << cnt << endl;
    // for(auto itr=memo.begin(); itr!=memo.end(); itr++) 
    // {
    //    cout << itr->first << " " << itr->second << endl;
    // }
    return 0;
} 
