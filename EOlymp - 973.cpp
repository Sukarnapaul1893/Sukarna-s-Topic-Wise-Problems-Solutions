#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define pii pair<int,int>
#define pll pair<long long ,long long>
#define pli pair<long long , int>
#define pil pair<int ,long long>
#define pi acos(-1)
#define pb push_back
#define mkp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAX 300005
#define INF 0x3f3f3f3f
#define mset(a,b) memset(a,b,sizeof(a))
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}
using namespace std;

vector<int>adj[100005];

ll dp[100005][2];
ll c[100005];

void dfs(int s,int p){
    ll sum1 = 0;
    ll sum2 = 0;

    for(int i=0;i<adj[s].size();i++){
        int v = adj[s][i];
        if(v==p)continue;
        dfs(v,s);
        sum1 += dp[v][1];
        sum2 += max(dp[v][1],dp[v][0]);
    }

    dp[s][0] = c[s] + sum1;
    dp[s][1] = sum2;
}

int main(){
	IOS
	//freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    memset(c,0,sizeof c);
    memset(dp,0,sizeof dp);
    for(int p=0;p<n-1;p++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i=1;i<n+1;i++){
        cin>>c[i];
    }
    dfs(1,1);
    cout<<max(dp[1][0],dp[1][1]);
}
