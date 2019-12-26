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


map<int,int>dis1,dis2,dis3;
map<pair<int,int> , int>cost;
unordered_map<int, vector<int> >adj;

unordered_map<int,int >vis;



void dfs(int s, int dist){
    dis1[s]=dist;
    vis[s]++;
    for(auto i=adj[s].begin();i!=adj[s].end();i++){
         if(vis[*i]==0){
            dfs(*i,dist+cost[{s,*i}]);
         }
    }
}
void dfs2(int s, int dist){
    dis2[s]=dist;
    vis[s]++;
    for(auto i=adj[s].begin();i!=adj[s].end();i++){
         if(vis[*i]==0){
            dfs2(*i,dist+cost[{s,*i}]);
         }
    }
}
void dfs3(int s, int dist){
    dis3[s]=dist;
    vis[s]++;
    for(auto i=adj[s].begin();i!=adj[s].end();i++){
         if(vis[*i]==0){
            dfs3(*i,dist+cost[{s,*i}]);
         }
    }
}
int main(){
    //IOS
    //freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);

    for(int tt=0;tt<t;tt++){
        int n;
        scanf("%d",&n);

        for(int j=0;j<n-1;j++){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);

            cost[{u,v}]=w;
            cost[{v,u}]=w;
            adj[u].pb(v);
            adj[v].pb(u);


        }

        dfs(0,0);
        int mx = -1;
        int e1;
        for(auto it=dis1.begin();it!=dis1.end();it++){
            if((*it).second>mx){
                e1 = (*it).first;
                mx = (*it).second;
            }
        }
        vis.clear();
        dfs2(e1,0);
        int e2;
        mx= -1;
        for(auto it=dis2.begin();it!=dis2.end();it++){
            if((*it).second>mx){
                e2 = (*it).first;
                mx = (*it).second;
            }
        }

        vis.clear();
        dfs3(e2,0);


        printf("Case %d:\n",tt+1);

        for(auto it=dis2.begin(),it2=dis3.begin();it!=dis2.end();it++,it2++){
            int a,b;
            a= (*it).second;
            b= (*it2).second;
            printf("%d\n",max(a,b));
        }

        dis1.clear();
        dis2.clear();
        dis3.clear();
        adj.clear();
        cost.clear();
        vis.clear();
    }
}
