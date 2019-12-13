#include<bits/stdc++.h>

#define pb push_back
#define ll long long
using namespace std;

int sum[120020];
int arr[100005];
int a[100005];

int query(int at, int L, int R, int l, int r){
    if(r<L || R<l)return 0;

    if(l<=L && R<=r){
        return sum[at];
    }

    int mid = (L+R)/2;

    int x = query(at*2,L,mid,l,r);
    int y = query(at*2+1,mid+1,R,l,r);

    return (x+y);
}
void update(int at, int L, int R, int pos, int u ){
    if(L==R){
        sum[at]+=u;
        return ;
    }

    int mid = (L+R)/2;

    if(pos<=mid){
        update(at*2,L,mid,pos,u);
    }
    else{
        update(at*2+1,mid+1,R,pos,u);
    }

    sum[at] = sum[at*2] + sum[at*2+1];
}



void build(int at , int L, int R){
    if(L==R){
        sum[at]=a[L];
        return;
    }
    int mid = (L+R)/2;
    build(at*2,L,mid);
    build(at*2+1,mid+1,R);
    sum[at]= sum[at*2]+sum[at*2+1];

}


int main(){

    int n;
    scanf("%d",&n);

    vector<pair<int,int> >findme;
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        findme.pb({arr[i],i});
    }
    sort(findme.begin(),findme.end());
    memset(a,0,sizeof a);
    build(1,1,n);

    int q;
    scanf("%d",&q);
    vector<pair<int,pair<pair<int,int>,int> > >qr;
    for(int ii=0;ii<q;ii++){
        int i,j,k;
        scanf("%d %d %d",&i,&j,&k);
        qr.pb({k,{{i,j},ii}});
    }
    sort(qr.begin(),qr.end());
    int j = n-1;
    int ans[q];
    for(int i=q-1;i>=0;i--){
        int curk = qr[i].first;

        while(findme[j].first>curk && j>=0 ){
            update(1,1,n,findme[j].second,1);
            j--;
            if(j<0)break;
        }
        int l =  qr[i].second.first.first;
        int r =  qr[i].second.first.second;
        int id = qr[i].second.second;

        ans[id] = query(1,1,n,l,r);

    }
    for(int i=0;i<q;i++){
        printf("%d\n",ans[i]);
    }
}
