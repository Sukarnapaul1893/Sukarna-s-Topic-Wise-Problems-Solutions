#include<bits/stdc++.h>
using namespace std;

struct Query{
    int L,R,idx,blk;
};
int block;
bool compare(Query a, Query b){
    if(a.blk != b.blk){
        return a.L/block < b.L/block;
    }
    return a.R < b.R;
}

int ans[100005];
int ase[100005];
int cnt[100005];
void query(int arr[], Query q[], int m){
    sort(q,q+m,compare);

    int currL = 0, currR=0;



    int mx=0;
    for(int i=0;i<m;i++){
       int L = q[i].L , R = q[i].R;

       while(currL<L){

            if(cnt[arr[currL]]>0)ase[cnt[arr[currL]]]--;
            if(ase[mx]==0 && mx>0){
                mx--;
            }
            cnt[arr[currL]]--;
            if(cnt[arr[currL]]>0)ase[cnt[arr[currL]]]++;

            currL++;
       }
       while(currL>L){

            if(cnt[arr[currL-1]]>0)ase[cnt[arr[currL-1]]]--;
            cnt[arr[currL-1]]++;
            if(cnt[arr[currL-1]]>0)ase[cnt[arr[currL-1]]]++;
            if(ase[mx+1]>0)mx++;
            currL--;
       }
       while(currR<=R){

            if(cnt[arr[currR]]>0)ase[cnt[arr[currR]]]--;
            cnt[arr[currR]]++;
            if(cnt[arr[currR]]>0)ase[cnt[arr[currR]]]++;
            if(ase[mx+1]>0)mx++;

            currR++;
       }
       while(currR>R+1){

            if(cnt[arr[currR-1]]>0)ase[cnt[arr[currR-1]]]--;
            if(ase[mx]==0 && mx>0){
                mx--;
            }
            cnt[arr[currR-1]]--;
            if(cnt[arr[currR-1]]>0)ase[cnt[arr[currR-1]]]++;

            currR--;
        }

        ans[q[i].idx]=mx;
    }

}

int main(){
    //IOS
    int n,qq;
    //cin>>n>>qq;
    scanf("%d %d",&n,&qq);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    block = sqrt(n);
    Query q[qq];


    for(int i=0;i<qq;i++){
        int l,r;
        scanf("%d %d",&l,&r);

        q[i].L=l;

        q[i].R=r;
        q[i].idx=i;
        q[i].blk=q[i].L/block;
    }
    query(arr,q,qq);
    for(int i=0;i<qq;i++){
        printf("%d\n",ans[i]);
    }

}
