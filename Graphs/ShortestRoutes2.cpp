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
    int n,m,q;
    cin>>n>>m>>q;

    vector<vector<long long>>dist(n+1,vector<long long>(n+1,1e18));
    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0; 
    }

    for(int i=0;i<m;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
        
    }
    
    for(int via=1;via<=n;via++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if (dist[i][via] < 1e18 && dist[via][j] < 1e18) dist[i][j]=min(dist[i][j],(long long)dist[i][via]+dist[via][j]);
            }
        }
    }

    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        if(dist[a][b]==1e18) cout<<-1<<endl;
        else cout<<dist[a][b]<<endl;
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

