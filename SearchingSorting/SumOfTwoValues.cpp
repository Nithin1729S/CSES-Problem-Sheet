#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define INF INT_MAX
#define MOD 1000000007
#define pii pair<int,int>
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define clr(x) memset(x,0,sizeof(x))
#define sortUni(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define test int t;cin>>t;while(t--)
#define f0(i,n) for(int i = 0; i < n; i++)
#define take(a,n) vi a(n); f0(i,n) cin >> a[i];
#define give(a,n) f0(i,n){cout << a[i] << ' ';}cout << endl;

void solve()
{
    int n,x;
    cin>>n>>x;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    vector<pair<int,int>>idxMap;
    for(int i=0;i<n;i++){
        idxMap.push_back({arr[i],i});
    }
    sort(idxMap.begin(),idxMap.end(),[](pair<int,int>&a,pair<int,int>&b){
        return a.first < b.first;
    });

    int i=0;
    int j=n-1;
    while(i<j){
        if(idxMap[i].first+idxMap[j].first == x){
            cout<<idxMap[i].second+1<<" "<<idxMap[j].second+1<<endl;
            return;
        }else if(idxMap[i].first+idxMap[j].first > x){
            j--;
        }else{
            i++;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}
int32_t main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    fast_io;
    //test
        solve();
    return 0;
}
