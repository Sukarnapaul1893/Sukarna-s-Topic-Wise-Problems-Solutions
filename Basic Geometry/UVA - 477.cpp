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
    double arr[10][4];
    char fig[10];
    int j=0;
    int total=0;
    while(true){
        char ch;
        cin>>ch;

        if(ch=='*')break;
        fig[j]=ch;
        double a,b,c,d;
        if(ch=='r'){
            cin>>a>>b>>c>>d;
            arr[j][0]=a;
            arr[j][1]=b;
            arr[j][2]=c;
            arr[j++][3]=d;
        }
        else{
            cin>>a>>b>>c;
            arr[j][0]=a;
            arr[j][1]=b;
            arr[j++][2]=c;
        }
        total++;
    }
    int p=1;
    while(true){
        double x,y;
        cin>>x>>y;
        if(x==9999.9 && y==9999.9)break;
        bool bl =false;
        for(int i=0;i<total;i++){
            if(fig[i]=='r'){
                if((x>arr[i][0] && x<arr[i][2]) && (y>arr[i][3] && y<arr[i][1])){
                    bl=true;
                    cout<<"Point "<<p<<" is contained in figure "<<i+1<<"\n";
                }
            }
            else{
                double distance = sqrt((x-arr[i][0])*(x-arr[i][0]) + (y-arr[i][1])*(y-arr[i][1]));
                if(distance<arr[i][2]){
                    bl=true;
                    cout<<"Point "<<p<<" is contained in figure "<<i+1<<"\n";
                }
            }
        }
        if(bl==false)cout<<"Point "<<p<<" is not contained in any figure\n";
        p++;
    }
}
