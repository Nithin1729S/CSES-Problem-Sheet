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
    vector<pair<int,pair<int,long long>>>edges;
    vector<vector<pair<int,long long>>>adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;
        edges.push_back({a,{b,-c}});
        adj[b].push_back({a,c});
    }

    vector<long long>dist(n+1,1e18);
    dist[1]=0;
    for(int i=0;i<n-1;i++){
        for(auto&it:edges){
            int u=it.first;
            int v=it.second.first;
            long long wt=it.second.second;

            if( dist[u]!=1e18 && dist[v]>dist[u]+wt){
                dist[v]=dist[u]+wt;
            }
        }
    }
    vector<int>changedDistance(n+1,0);
    for(auto&it:edges){
        int u=it.first;
        int v=it.second.first;
        long long wt=it.second.second;
        if(dist[u]!=1e18 && dist[v]>dist[u]+wt){
            dist[v] = dist[u] + wt;
            changedDistance[u]=1;
            changedDistance[v]=1;
        }
    }

    queue<int>q;
    vector<int>vis(n+1,0);
    q.push(n);
    vis[n]=1;
    while(!q.empty()){
        auto node=q.front();q.pop();
        for(auto&it:adj[node]){
            if(!vis[it.first]){
                vis[it.first]=1;
                q.push(it.first);
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(vis[i]==1 && changedDistance[i]==1){
            cout<<-1<<endl;
            return;
        }
    }



    cout<<-dist[n]<<endl;

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

