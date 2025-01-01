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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>desiredSize;
    vector<int>apartmentSize;

    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        desiredSize.push_back(ele);
    }

    for(int i=0;i<m;i++){
        int ele;
        cin>>ele;
        apartmentSize.push_back(ele);
    }
    
    sort(desiredSize.begin(),desiredSize.end());
    sort(apartmentSize.begin(),apartmentSize.end());

    int i=0;
    int j=0;
    int count=0;

    while (i < n && j < m) {
        if (desiredSize[i] >= apartmentSize[j] - k && desiredSize[i] <= apartmentSize[j] + k) {
            // Match found
            count++;
            i++;
            j++;
        } else if (desiredSize[i] < apartmentSize[j] - k) {
            // Applicant's desired size is too small, move to the next applicant
            i++;
        } else {
            // Apartment is too small, move to the next apartment
            j++;
        }
    }
    cout<<count<<endl;




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

