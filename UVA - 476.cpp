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


int main(){
	IOS
	//freopen("output.txt","w",stdout);
    double rec[10][4];
    int j=0;
    int total=0;
    while(true){
        char ch;
        cin>>ch;
        if(ch=='*')break;
        double a,b,c,d;
        cin>>a>>b>>c>>d;
        rec[j][0]=a;
        rec[j][1]=b;
        rec[j][2]=c;
        rec[j++][3]=d;
        total++;
    }
    int p=1;
    while(true){
        double x,y;
        cin>>x>>y;
        if(x==9999.9 && y==9999.9)break;
        bool bl =false;
        for(int i=0;i<total;i++){
            if((x>rec[i][0] && x<rec[i][2]) && (y>rec[i][3] && y<rec[i][1])){
                bl=true;
                cout<<"Point "<<p<<" is contained in figure "<<i+1<<"\n";
            }
        }
        if(bl==false)cout<<"Point "<<p<<" is not contained in any figure\n";
        p++;
    }
}
