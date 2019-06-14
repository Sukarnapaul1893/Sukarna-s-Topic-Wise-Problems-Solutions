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
#define ll double
#define pdd pair<double, double>
#define MAX 300005
#define INF 0x3f3f3f3f
#define mset(a,b) memset(a,b,sizeof(a))
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}
using namespace std;




pdd lineLineIntersection(pdd A, pdd B, pdd C, pdd D)
{
    // Line AB represented as a1x + b1y = c1
    double a1 = B.second - A.second;
    double b1 = A.first - B.first;
    double c1 = a1*(A.first) + b1*(A.second);

    // Line CD represented as a2x + b2y = c2
    double a2 = D.second - C.second;
    double b2 = C.first - D.first;
    double c2 = a2*(C.first)+ b2*(C.second);

    double determinant = a1*b2 - a2*b1;

    if (determinant == 0)
    {
        // The lines are parallel. This is simplified
        // by returning a pair of FLT_MAX
        return make_pair(FLT_MAX, FLT_MAX);
    }
    else
    {
        double x = (b2*c1 - b1*c2)/determinant;
        double y = (a1*c2 - a2*c1)/determinant;
        return make_pair(x, y);
    }
}

ll triangle_area (ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
    return (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2;
}

int main(){
	IOS
	//freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    cout<<"INTERSECTING LINES OUTPUT\n";
    for(int i=0;i<t;i++){
            ll x1,y1,x2,y2,x3,y3,x4,y4;
            cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;


            ll a = triangle_area(x1,y1,x2,y2,x3,y3);
            ll b = triangle_area(x1,y1,x2,y2,x4,y4);

            if(a==0 and a==b){
                cout<<"LINE\n";
            }
            else if(a==b){
                cout<<"NONE\n";
            }
            else{
                cout<<"POINT ";
                auto pnt = lineLineIntersection({x1,y1},{x2,y2},{x3,y3},{x4,y4});
                double x = pnt.first;
                double y = pnt.second;
                cout<<fixed<<setprecision(2)<<x<<" "<<y<<"\n";
            }
        }
        cout<<"END OF OUTPUT\n";
}
