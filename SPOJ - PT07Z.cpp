#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
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

vector<int>adj[100005];

bool vis[100005];
int m,mx;
void dfs(int s,int lvl){
    if(lvl>mx){
        mx=lvl;
        m = s;
    }
    vis[s]=true;
    for(int i=0;i<adj[s].size();i++){
        if(vis[adj[s][i]]==true)continue;
        dfs(adj[s][i],lvl+1);
    }
}

int main(){
    IOS
    //freopen("output.txt","w",stdout);
    int n;
    cin>>n;

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    memset(vis,false,sizeof vis);
    mx=-1;
    dfs(1,0);
    //cout<<m<<" "<<mx;
    memset(vis,false,sizeof vis);
    mx=-1;
    dfs(m,0);
    cout<<mx;
}
