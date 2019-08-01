#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int n,vis[200005],p[200005];
priority_queue<pair<int,int> >q;
vector<pair<int,int> >v[200005];

void mst(){
    int i,f,c,x;
    ll sum=0;

    for(int i=1;i<=n;i++){
        vis[i]=2e9;
        p[i]=-1;
    }

    vis[1]=0;
    q.push({0,1});

    while(!q.empty()){
        f = q.top().second;
        c = -q.top().first;
        q.pop();
        if(p[f]!=-1)continue;

        p[f]=1;
        sum+=c;

        for(int i=0;i<v[f].size();i++){
            x=v[f][i].first;
            c=v[f][i].second;
            if(vis[x]>c){
                vis[x]=c;
                q.push({-c,x});
            }
        }

    }
    printf("%lld",sum);
}

int main(){
    int m,a,b,w;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&a,&b,&w);

        v[a].pb({b,w});
        v[b].pb({a,w});
    }
    mst();
    return 0;

}
