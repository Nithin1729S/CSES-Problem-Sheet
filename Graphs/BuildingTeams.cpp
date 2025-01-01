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


bool isBipartite(int node,vector<int>&color,vector<vector<int>>&graph){
    queue<int>q;
    q.push(node);
    color[node]=1;
    while(!q.empty()){
        int curr=q.front();q.pop();
        for(auto&it:graph[curr]){
            if(color[it]==-1){
                color[it]=!color[curr];
                q.push(it);
            }else if(color[it]==color[curr]){
                return false;
            }
        }
    }
    return true;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>color(n+1,-1);
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            if(isBipartite(i,color,adj)==false){
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<(color[i]+1)<<" ";
    }
    
   

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

