#include <bits/stdc++.h>

using namespace std;

#define nl '\n'
#define sp ' '
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define si unordered_set<int>
#define sl unordered_set<ll>
#define tsi set<int>
#define tsl set<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define tmii map<int,int>
#define tmll map<ll,ll>
#define mii unordered_map<int,int>
#define mll unordered_map<ll,ll>
#define pqi priority_queue<int>
#define pqig priority_queue<int,vi,less<int>>
#define pql priority_queue<ll>
#define pqlg priority_queue<ll,vl,less<ll>>
#define pqpii priority_queue<pii>
#define pqpll priority_queue<pll>

#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define outrange(x,min,max) ((x)<(min) || (x)>(max))

#define nano (chrono::system_clock::now().time_since_epoch().count())
#define init_rng mt19937 rng(nano)

inline void yesno(bool a){
	cout<<(a?"YES\n":"NO\n");
}

template<typename L,typename R>
ostream& operator<<(ostream& out,pair<L,R>& p){
	out<<'('<<p.first<<','<<p.second<<')';
	return out;
}

template<typename T>
ostream& operator<<(ostream& out,vector<T>& v){
	for(auto &i:v) out<<i<<' ';
	out<<nl;
	return out;
}

template<typename T>
ostream& operator<<(ostream& out,set<T>& v){
	for(auto &i:v) out<<i<<' ';
	out<<nl;
	return out;
}

template<typename T>
ostream& operator<<(ostream& out,unordered_set<T>& v){
	for(auto &i:v) out<<i<<' ';
	out<<nl;
	return out;
}

template<typename K,typename V>
ostream& operator<<(ostream& out,map<K,V>& m){
	out<<'[';
	for(auto &[k,v]:m) {
		out<<k<<':'<<v<<sp;
	}
	out<<"]\n";
	return out;
}

template<typename K,typename V>
ostream& operator<<(ostream& out,unordered_map<K,V>& m){
	out<<'[';
	for(auto &[k,v]:m) {
		out<<k<<':'<<v<<sp;
	}
	out<<"]\n";
	return out;
}

#ifdef adj8
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
#endif
#ifdef adj4
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
#endif

const int MAX=200005;
int c[MAX];
vvi adj;
vi dist, cntv;

int cnt = 0;

void dfs(int node,int parent,int d,int max_depth){
  cnt++;
	if(d>=dist[node]) return;
	dist[node]=d;
	if(d+1>=max_depth) return;
	for(int child:adj[node]){
		if(child==parent) continue;
		dfs(child,node,d+1,max_depth);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int _t;
	cin>>_t;
	while(_t--){
		int n,c0;
		cin>>n>>c0;
		for(int i=1;i<n;i++){
			cin>>c[i];
		}
		adj=*(new vvi(n+1,vi()));
		dist=*(new vi(n+1,1000000));
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs(c0,0,0,1000000);
		int ans=1000000;
		for(int i=1;i<n;i++){
			int node=c[i];
			ans=min(ans,dist[node]);
			cout<<ans<<sp;
			dfs(node,0,0,ans);
      cntv.push_back(cnt);
		}
		cout<<nl;
	}
  cout << cntv << endl;
}