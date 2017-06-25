#include <bits/stdc++.h>
using namespace std;

/***********************************************/
/* Dear online judge:
 * I've read the problem, and tried to solve it.
 * Even if you don't accept my solution, you should respect my effort.
 * I hope my code compiles and gets accepted.
 *  ___  __     _______    _______      
 * |\  \|\  \  |\  ___ \  |\  ___ \     
 * \ \  \/  /|_\ \   __/| \ \   __/|    
 *  \ \   ___  \\ \  \_|/__\ \  \_|/__  
 *   \ \  \\ \  \\ \  \_|\ \\ \  \_|\ \ 
 *    \ \__\\ \__\\ \_______\\ \_______\
 *     \|__| \|__| \|_______| \|_______|
 */
//const long long mod = 1000000007;
const long long mod = 10007;

const int all = mod - 1;
long long dp[mod];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	dp[0] = 1,dp[1] = 2;
	for(int i = 2;i < 10007;i++) {
		dp[i] = (2 * dp[i-1] + 2 * dp[i-2])%mod;
	}
	long long N;
	while(cin>>N && N >= 0) {
		if(false) N = rand() % (mod * mod);
		long long res = 0;
		if(N < all) {
			for(long long k = 0;k <= N;k++) {
				res = (res + dp[k%all] * dp[(N-k)%all])%mod;
			}
			cout<<res<<'\n';
			continue;
		}
		long long numCyc = (N+1)/all;
		long long Cycres = 0;
		for(long long k = 0;k < all;k++) {
			Cycres = (Cycres + dp[k] * dp[(N-k)%all])%mod;
		}
		res = Cycres * numCyc % mod;
		for(long long k = numCyc * all;k <= N;k++) {
			res = (res + dp[k%all] * dp[(N-k)%all])%mod;
		}
		if(false) { // stress test
			long long corres = 0;
			for(long long k = 0;k <= N;k++) {
				corres = (corres + dp[k%all] * dp[(N-k)%all])%mod;
			}
			assert(corres == res);
		}
		cout<<res<<'\n';
	}
	return 0;
}
