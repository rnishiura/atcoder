#include <bits/stdc++.h>
#define square(z) ((z)*(z))
#define print(z) cout << z << endl;
#define MOD 998244353
using namespace std;
using  ll = long long;
using   v = vector<ll>;
using  vv = vector<vector<ll>>;
using  vp = vector<pair<ll, ll>>;
using vvp = vector<vector<pair<ll, ll>>>;

void print_v(v a) {
  for(auto item: a) cout << item << " ";
  cout << endl;
}
void print_vv(vv a) { 
  for(auto item: a) print_v(item); 
}
void print_vp(vp a) {
  for(auto item: a) cout << "(" << item.first << " " << item.second << ") ";
  cout << endl;
}
void print_vvp(vvp a) { 
  for(auto item: a) print_vp(item); 
}

void CombinationRepetitionUtil(int chosen[], int arr[],
                    int index, int r, int start, int end)
{
    // Since index has become r, current combination is
    // ready to be printed, print
    if (index == r)
    {
        for (int i = 0; i < r; i++)
            cout<<" "<< arr[chosen[i]];
        cout<<"\n";
        return;
    }
 
    // One by one choose all elements (without considering
    // the fact whether element is already chosen or not)
    // and recur
    for (int i = start; i <= end; i++)
    {
        chosen[index] = i;
        CombinationRepetitionUtil(chosen, arr, index + 1,
                                               r, i, end);
    }
    return;
}
 
// The main function that prints all combinations of size r
// in arr[] of size n with repetitions. This function mainly
// uses CombinationRepetitionUtil()
void CombinationRepetition(int arr[], int n, int r)
{
    // Allocate memory
    int chosen[r+1];
 
    // Call the recursive function
    CombinationRepetitionUtil(chosen, arr, 0, r, 0, n-1);
}
 
// Driver program to test above functions
int main()
{
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int r = 2;
    CombinationRepetition(arr, n, r);
    return 0;
}
// this code is contributed by shivanisinghss2110

int main(void) {
  ll N, M;
  cin >> N >> M;

  vector<string> S(N);
  for(ll i=0; i<N; i++) cin >> S[i]; 

  string t;
  set<string> T;
  for(ll i=0; i<M; i++) {
    cin >> t;
    T.insert(t);
  }

  if(N==1) {
    if(T.find(S[0]) == T.end()) {
      print(S[0]);
      return 0;
    }
  }

  do {    
    vector<string> SS;
    ll len = 0;
    for(ll i=0; i<N-1; i++) {
      SS.push_back(S[i]+"_");
      len += S[i].length() + 1;
    }
    SS.push_back(S[N-1]);
    len += S[N-1].length();
    for(ll c=0; len+c<=16; c++) {

      if(ts.length() < 3) continue;
      if(T.find(ts) == T.end()) {
        print(ts);
        return 0;
      }
    }
  
  } while(next_permutation(S.begin(), S.end()));
  print("-1")
}
