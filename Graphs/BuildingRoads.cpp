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

class DisjointSet{
    vector<int>parent;
    vector<int>rank;
    public:
    DisjointSet(int n ){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }

    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUPar(parent[node]);
    }

    void unionByRank(int u,int v){
        int up=findUPar(u);
        int vp=findUPar(v);
        if(up==vp){
            return ;
        }
        if(rank[up]>rank[vp]){
            parent[vp]=up;
        }else if(rank[up]<rank[vp]){
            parent[up]=vp;
        }else{
            parent[up]=vp;
            rank[vp]++;
        }
    }
};


void solve()
{
    int n,m;
    cin>>n>>m;
    DisjointSet ds(n);
    for(int i=0;i<m;i++)
    {
        int x;
        int y;
        cin>>x>>y;
        ds.unionByRank(x,y);
    }
    
    // Find representatives of all components
    vector<int> representatives;
    for (int i = 1; i <= n; i++) {
        if (ds.findUPar(i) == i) {
            representatives.push_back(i);
        }
    }

    // Connect all components
    int newRoads = representatives.size() - 1;
    cout << newRoads << endl;
    for (int i = 1; i < representatives.size(); i++) {
        cout << representatives[i - 1] << " " << representatives[i] << endl;
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

