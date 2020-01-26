#include<bits/stdc++.h>

#define pb push_back
using namespace std;
long long m;
struct mat{
    long long arr[6][6];
};
mat mul ( mat a , long long rowa , long long cola , mat b , long long rowb , long long colb ){
    mat ans ;  /// size = rowa * colb

    for ( long long i = 1 ; i<= rowa ; i ++ ){
        for ( long long j = 1 ; j<=colb ; j ++ ) {
            ans.arr[i][j] = 0;

            for ( long long k = 1 ; k <= cola ; k ++ ) {
                ans . arr [ i ] [ j ] += (a . arr[ i ] [ k ] %m) * (b . arr[ k ] [ j ] %m) ;
                ans.arr[i][j]%=m;
            }

        }
    }

    return ans ;
}
mat power ( mat a , long long n  , long long row ) {

    if(n == 0 ){
        mat idn;
        memset ( idn.arr, 0 , sizeof idn.arr);
        for ( long long i = 1 ; i <= row ; i ++) idn.arr [ i ] [ i ]  = 1;
        return idn;
    }
    long long tn= n/2;
    mat ans = power(a,tn,row) ;

    ans = mul ( ans , row , row , ans  , row , row ) ;

    if ( n & 1 ) ans = mul ( ans , row , row , a , row , row ) ;

    return ans ;

}

int main(){
    long long t;
    scanf("%lld",&t);

    for(long long tt=0;tt<t;tt++){
        long long aa,bb,cc,n;
        scanf("%lld %lld %lld %lld",&n,&aa,&bb,&cc);
        if(n<=2){
            printf("Case %lld: 0\n",tt+1);
            continue;
        }
        mat fib;

        m = 10007;
        fib.arr[1][1] = 0;
        fib.arr[2][1] = 0;
        fib.arr[3][1] = 0;
        fib.arr[4][1] = 1;
        mat a ;

        a.arr[1][1] = aa;
        a.arr[1][2] = 0;
        a.arr[1][3] = bb;
        a.arr[1][4] = cc;

        a.arr[2][1] = 1;
        a.arr[2][2] = 0;
        a.arr[2][3] = 0;
        a.arr[2][4] = 0;

        a.arr[3][1] = 0;
        a.arr[3][2] = 1;
        a.arr[3][3] = 0;
        a.arr[3][4] = 0;

        a.arr[4][1] = 0;
        a.arr[4][2] = 0;
        a.arr[4][3] = 0;
        a.arr[4][4] = 1;

        //a.arr[2][2] = 0;
        mat tmp = power ( a , n - 2, 4 ) ;
        mat ans = mul ( tmp , 4 , 4 , fib , 4 , 1);
        long long final_ans = ans.arr[1][1];
        printf("Case %lld: %lld\n",tt+1,final_ans%m);

    }
}
