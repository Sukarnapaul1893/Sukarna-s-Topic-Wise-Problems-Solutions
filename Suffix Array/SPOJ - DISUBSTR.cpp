#include<bits/stdc++.h>
#define N 100005
using namespace std;

/// suffix array
int cmp_for_sa(int *r,int a,int b,int l){
    return (r[a]==r[b]) && (r[a+l]==r[b+l]);
}
int wa[N],wb[N],wws[N],wv[N],rnk[N],lcp[N], sa[N],data[N];
void DA(int *r,int *sa,int n,int m){
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++) wws[i]=0;
    for(i=0;i<n;i++) wws[x[i]=r[i]]++;
    for(i=1;i<m;i++) wws[i]+=wws[i-1];
    for(i=n-1;i>=0;i--) sa[--wws[x[i]]]=i;
    for(j=1,p=1;p<n;j*=2,m=p){
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) wws[i]=0;
        for(i=0;i<n;i++) wws[wv[i]]++;
        for(i=1;i<m;i++) wws[i]+=wws[i-1];
        for(i=n-1;i>=0;i--) sa[--wws[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++) x[sa[i]]=cmp_for_sa(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}
void cal_lcp(int *r,int *sa,int n){
    int i,j,k=0;
    for(i=1;i<=n;i++) rnk[sa[i]]=i;
    for(i=0;i<n;lcp[rnk[i++]]=k)
        for(k?k--:0,j=sa[rnk[i]-1];r[i+k]==r[j+k];k++);
}
void suffix_array (char *A){
    int n = strlen(A) ;
    for(int i = 0; i<=128; i++){
        wa[i] = wb[i] = wws[i] = wv[i] = rnk[i] = lcp[i] = sa[i] = data[i] = 0;
    }
    for (int i = 0 ; i <= n ; i++) {
        wa[i] = wb[i] = wws[i] = wv[i] = rnk[i] = lcp[i] = sa[i] = data[i] = 0;
        if(i<n) data[i] = A[i] ;
    }
    DA(data,sa,n+1,128);
    cal_lcp(data,sa,n);
    for (int i = 0 ; i < n ; i++) { /// transforming it into 0-based SA
        sa[i] = sa[i+1] ;
        lcp[i] = lcp[i+2] ;
        rnk[i]--;
    }
}
char s[1005];

int main(){
    int t;
    scanf("%d",&t);

    for(int tt=0;tt<t;tt++){

        scanf("%s",s);

        suffix_array(s);
        //continue;
        int n = strlen(s);

        long long sum =0;
        for(int i=0;i<n-1;i++){
            sum+=lcp[i];
        }
        cout<<(n*(n+1))/2-sum<<"\n";
        for(int i=0;i<=n;i++){
            wa[i]=0;
            wb[i]=0;
            wws[i]=0;
            wv[i]=0;
            rnk[i]=0;
            lcp[i]=0;
            sa[i]=0;
            data[i]=0;
        }
    }

}
