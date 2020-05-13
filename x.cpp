/*
 * you can use dp [i][j] as you are at the i'th element and have made j groups so far 
 * instead of trying all the previous I ( I < i ) as dp[i][j] = min ( dp[i][j] ,dp[I][j-1] + Mx ( I+1,i) ) 
 * we will greedly try just I ( I < i ) if  Mx ( I+1 , i ) =  a[i] or we will try to put the current element with last block as dp [i][j] = dp [last][j] where last is the first element before i achieve a[last] > a[i] 
 * https://oj.uz/submission/231168 here is the greedy checking using brute force
 * https://oj.uz/submission/231172 here is a solution using segment tree but it didnt pass
 * reading last codes will help to understand the idea correctly
 * in this code we are using a stack
*/ 
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 547
//#define mp make_pair
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
ll n , k ;
ll a[100009] ;
ll dp [100009][109] ;
int main () {
	scanf("%lld%lld",&n,&k) ;
	for ( int i = 1 ; i <= n ; i ++ ) scanf("%lld",&a[i]) ; 
	for ( int i = 1 ; i <= n ; i ++ ) {
		dp [i][1] = max ( dp [i-1][1] , a[i] ) ;
	}
	dp [0][1] = inf ;
	for ( int i = 0 ; i <= n ; i ++ ) {
		for ( int j = 2 ; j <= k ; j ++ ) {
			dp [i][j] = inf ;
		}
	}
	for ( int j = 2 ; j <= k ; j ++ ) {
		stack < pll > st ; 
		for ( int i = 1 ; i <  j ; i ++ ) st .push ( { i , dp [i][j-1] } ) ;
		for ( int i = j ; i <= n ; i ++ ) {
			ll val1 = dp[i-1][j-1] , val2 = inf ; 
			while ( st . size () ) {
				ll id = st.top ().fi , crnt = st.top().se ; 
				if ( a [id] > a[i] ) break ;
				val1 = min ( val1 , crnt ) ;
				st .pop () ;
			}
			if ( st . size () ) val2 = dp [st.top().fi][j] ;
			st .push ( { i , val1  } ) ;
			val1 += a[i] ;
			dp [i][j] = min ( val1 , val2 ) ;
		}
	}
	cout << dp[n][k] << endl ; 
}
