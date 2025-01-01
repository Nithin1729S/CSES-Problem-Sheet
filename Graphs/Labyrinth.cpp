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

bool isValid(int x, int y, int n, int m) {
    return !(x < 0 || x >= n || y < 0 || y >= m);
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string>grid(n);
    for(int i=0;i<n;i++)
    {
        cin>>grid[i];
    }
    int src_x,src_y,dest_x,dest_y;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='A'){
                src_x=i;
                src_y=j;
            }else if(grid[i][j]=='B'){
                dest_x=i;
                dest_y=j;
            }
        }
    }

    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<vector<char>>path(n,vector<char>(m));
    vector<vector<int>>dist(n,vector<int>(m,1e9));

    vis[src_x][src_y]=1;
    dist[src_x][src_y]=0;
    vector<int>dx{1,0,-1,0};
    vector<int>dy{0,1,0,-1};
    vector<char>dir{'D','R','U','L'};

    queue<pair<int,int>>q;
    q.push({src_x,src_y});

    while(!q.empty()){
        auto node=q.front();q.pop();
        for(int i=0;i<4;i++){
            int newX=node.first+dx[i];
            int newY=node.second+dy[i];
            if(isValid(newX,newY,n,m) && grid[newX][newY]!='#' && dist[newX][newY]>dist[node.first][node.second]+1){

                dist[newX][newY]=dist[node.first][node.second]+1;
                vis[newX][newY]=1;
                path[newX][newY]=dir[i];
                q.push({newX,newY});
            }
        }
    }

    if (vis[dest_x][dest_y]) {
    cout << "YES" << endl;
    cout << dist[dest_x][dest_y] << endl;

    string res = "";
    int x = dest_x, y = dest_y;

    while (x != src_x || y != src_y) {
        char move = path[x][y];
        res += move;
        if (move == 'D') x--;  // Moving back from 'D' (Down) means x--
        else if (move == 'R') y--;  // Moving back from 'R' (Right) means y--
        else if (move == 'U') x++;  // Moving back from 'U' (Up) means x++
        else if (move == 'L') y++;  // Moving back from 'L' (Left) means y++
    }

    reverse(res.begin(), res.end());
    cout << res << endl;
} else {
    cout << "NO" << endl;
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

