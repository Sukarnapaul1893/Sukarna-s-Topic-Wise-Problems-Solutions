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

vector<int>adj[705];
bool vis[705];
int parent[705];
int disc[705];
int low[705];

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
            }
        }
        else if(v!=parent[u]){
            low[u]=min(low[u],disc[v]);
        }
    }
}


int main(){
	IOS
	//freopen("output.txt","w",stdout);
    int t;
    cin>>t;

    for(int tt=0;tt<t;tt++){


        bridge.clear();
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

        for(int i=0;i<n;i++){
            if(vis[i]==false){
                dfs(i);
            }
        }
        sort(bridge.begin(),bridge.end());
        cout<<"Caso #"<<tt+1<<"\n";
        if(bridge.size()==0){
            cout<<"Sin bloqueos\n";
        }
        else{
            cout<<bridge.size()<<"\n";
            for(int i=0;i<bridge.size();i++){
                cout<<bridge[i].first+1<<" "<<bridge[i].second+1<<"\n";
            }
        }

        for(int i=0;i<n;i++){
            adj[i].clear();
        }
    }
}
