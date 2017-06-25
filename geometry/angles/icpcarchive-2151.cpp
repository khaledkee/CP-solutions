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
const long long mod = 1000000007;

const int mxN = 51;
double dp[mxN][mxN];

const double TAU = 2.0 * acos(-1.0);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cout<<fixed<<setprecision(6);
	int N,M;
	while(cin>>N>>M && N) {
		vector<double> p(N);
		for(int i = 0;i < N;i++) cin>>p[i], p[i] *= TAU;
		double res = 0;
		for(int s = 0;s < N-M+1;s++) {
			memset(dp,0,sizeof dp);
			for(int d = 1;d < N-s;d++) {
				int e = s + d;
				dp[d][2] = sin(p[e] - p[s]);
				for(int k = 3;k <= min(d+1,M);k++) {
					dp[d][k] = INT_MIN;
					for(int prev = s+k-2;prev < e;prev++) {
						dp[d][k] = fmax(dp[d][k],dp[prev-s][k-1] + sin(p[e]-p[prev]));
					}
					if(k == M) {
						res = fmax(res,dp[d][k] + sin(p[s]+TAU-p[e]));
					}
				}
			}
		}
		cout<<res/2.0<<'\n';
	}
	return 0;
}
