#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
#define pii pair<int,int>
#define pll pair<long long ,long long>
#define pli pair<long long , int>
#define pil pair<int ,long long>
#define pi acos(-1)
#define pb push_back
#define mkp make_pair
#define all(a) a.begin(), a.end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAX 300005
#define INF 0x3f3f3f3f
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}

using namespace std;
using namespace __gnu_pbds;

typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>pref_trie;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

vector<int>adj[100005];
bool vis[100005];

int dp[100005][2];
int dfs(int s, bool bl, int par){
    int sum;
    if(bl==false){
        if(dp[s][0]!=-1)return dp[s][0];
    }
    if(bl==true){
        if(dp[s][1]!=-1)return dp[s][1];
    }
    if(bl==true)sum=1;
    if(bl==false)sum=0;
    for(int i=0;i<adj[s].size();i++){
        if(adj[s][i]==par)continue;
        if(bl==false)sum+=dfs(adj[s][i],true,s);
        if(bl==true){
            sum+=min(dfs(adj[s][i],false,s),dfs(adj[s][i],true,s));
        }
    }
    if(bl==false)dp[s][0]=sum;
    if(bl==true)dp[s][1]=sum;
    return sum;
}


int main(){
    IOS
    //freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int ans = min(dfs(1,false,0),dfs(1,true,0));
    cout<<ans<<"\n";
}
