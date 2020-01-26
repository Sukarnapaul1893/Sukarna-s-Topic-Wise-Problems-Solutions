#include<bits/stdc++.h>

#define pb push_back
using namespace std;
long long m;
struct mat{
    long long arr[5][5];
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
        long long aa,bb,n;
        scanf("%lld %lld %lld %lld",&aa,&bb,&n,&m);
        mat fib;
        long long M=1LL;
        for(int i=0;i<m;i++){
            M*=10;
        }
        m = M;
        fib.arr[1][1] = bb%m;
        fib.arr[2][1] = aa%m;
        mat a ;
        for ( long long i = 1 ; i<=2; i++){
            for( long long j = 1 ; j <=2; j++) a.arr[ i ] [ j ] = 1;
        }

        a.arr[2][2] = 0;
        mat tmp = power ( a , n - 1 , 2 ) ;
        mat ans = mul ( tmp , 2 , 2 , fib , 2 , 1);
        long long final_ans = ans.arr[1][1];
        printf("Case %lld: %lld\n",tt+1,final_ans%m);

    }
}
