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
    double ha,hb,hc;
    int n;
    cin>>n;

    while(cin>>ha>>hb>>hc){


        double x = 1.0/ha;
        double y = 1.0/hb;
        double z = 1.0/hc;
        if(x+y-z<0 || y+z-x<0 || z+x-y<0 || x+y+z<0){
            cout<<"These are invalid inputs!\n";

            n--;
            if(n==0)break;
            continue;
        }
        double s = (x+y+z)*(x+y-z)*(y+z-x)*(z+x-y);

        double area = sqrt(1.0/s);

        double a = (area*2)/ha;
        double b = (area*2)/hb;
        double c = (area*2)/hc;

        if((a*ha)/2.0==area && (b*hb)/2.0==area && (c*hc)/2.0==area){
            cout<<fixed<<setprecision(3)<<area<<"\n";
        }
        else{
            cout<<"These are invalid inputs!\n";
            n--;
        }
        if(n==0)break;
    }
}
