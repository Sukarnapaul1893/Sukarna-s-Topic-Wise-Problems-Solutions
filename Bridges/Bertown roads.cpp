//Number of bridges in a graph

#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
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
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

vector<pair<int,int> >bridge;
vector<pair<int,int> >ans;

vector<int>adj[200005];
bool vis[200005];
int parent[200005];
int disc[200005];
int low[200005];
map<pair<int,int> ,int>visedge;

void dfs(int u){
    static int time = 0;
    vis[u]=true;
    disc[u]=low[u]=++time;

    for(int i=0;i<adj[u].size();i++){

        int v = adj[u][i];
        if(vis[v]==false){
            parent[v]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>disc[u]){
                bridge.pb({min(u,v),max(u,v)});
                cout<<0;
                exit(0);
            }
        }
        else if(v!=parent[u]){
            low[u]=min(low[u],disc[v]);
        }
    }
}

void dfs2(int u){
    vis[u]=true;

    for(int i=0;i<adj[u].size();i++){
        int v =adj[u][i];
        if(visedge[{min(u,v),max(u,v)}]==0){
            ans.pb({u,v});
            visedge[{min(u,v),max(u,v)}]++;
        }
        if(vis[v]==false){


            dfs2(v);
        }

    }
}
int main(){
	IOS
	//freopen("output.txt","w",stdout);

    memset(vis,false,sizeof vis);
    memset(parent,-1,sizeof parent);

    int n,m;
    cin>>n>>m;

    for(int q=0;q<m;q++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(0);


    if(bridge.size()>0){
        cout<<"0\n";
    }
    else{
        memset(vis,false,sizeof vis);
        dfs2(0);
        for(auto it=ans.begin();it!=ans.end();it++){

            cout<<(*it).first+1<<" "<<(*it).second+1<<"\n";
        }
    }
}
