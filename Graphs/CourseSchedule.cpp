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
    vector<vector<int>>graph(n+1);
    vector<int>res;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    vector<int>indegree(n+1,0);
    for(int i=1;i<=n;i++){
        for(auto&it:graph[i]){
            indegree[it]++;
        }
    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node=q.front();q.pop();
        res.push_back(node);
        for(auto&it:graph[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }

    if(res.size()!=n){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    for(auto&it:res){
        cout<<it<<" ";
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

