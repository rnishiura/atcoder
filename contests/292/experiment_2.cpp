void solve() {
  ll n, m; cin >> n >> m;

  vv g(n+1); ll u0, u1;
  rep(i, m) { cin >> u0 >> u1; g[u0].pb(u1); g[u1].pb(u0); }

  v d(n+1, -1); d[1] = 0;
  v fr = {1};
  ll cnt = 1;
  while(fr.size()) {
    v to;
    for(auto f: fr) {
      for(auto t: g[f]) {
        if(d[t] == -1) {
          d[t] = cnt;
          to.pb(t);
        }
      }
    }
    cnt++;
    fr.swap(to);
  }

  repi(i, 1, n+1) {
    print(d[i]);
  }
}
