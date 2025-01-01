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
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>vis(n+1,0);
    vector<int>dist(n+1,1e9);
    vector<int>path(n+1);

    queue<int>q;
    q.push(1);
    vis[1]=1;
    dist[1]=0;
    while(!q.empty()){
        int node=q.front();q.pop();
        for(auto&it:adj[node]){
            if(!vis[it] && dist[it]> dist[node]+1){
                dist[it]=dist[node]+1;
                vis[it]=1;
                path[it]=node;
                q.push(it);
            }
        }
    }

    if(vis[n]){
        cout<<dist[n]+1<<endl;
        int x=n;
        vector<int>res;
        while(x!=1){
            res.push_back(x);
            x=path[x];
        }
        res.push_back(1);
        reverse(res.begin(),res.end());
        for(auto&it:res) cout<<it<<" ";
    }else{
        cout<<"IMPOSSIBLE"<<endl;
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

