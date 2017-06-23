// Problem link: http://codeforces.com/group/gRkn7bDfsN/contest/210418/problem/B3
/*
 * Idea:
 * 1. Calculate the number of sets S that belongs to set X
 * 2. Calculate the number of pairs of sets S that their union belong to set X
 * 3. Calculate the number of pairs of sets S that their union is exactly set X
 * 4. Calculate the number of pairs of sets S that their union contains set X
 * More info can be found here: http://codeforces.com/blog/entry/45223
 */

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

long long sum[(1<<20)];
const int all = ((1<<20)-1);

int get(string s) {
	int res = 0;
	for(int i = 0;i < (int)s.size();i++) {
		res |= (1<<i) * (s[i] == '1');
	}
	return res;
}

string get(int x) {
	string s;
	for(int i = 0;i < 20;i++) s += ((x&(1<<i)) != 0) + '0';
	return s;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long N,Q;
	cin>>N>>Q;
	string s;
	for(int i = 0;i < N;i++) {
		cin>>s;
		sum[get(s)] ++;
	}
	for(int i = 0;i < 20;i++) {
		for(int m = 0;m < (1<<20);m++) {
			if(m&(1<<i))
				sum[m] += sum[m^(1<<i)];
		}
	}
	//	for(int m = 0;m < (1<<20);m++) cerr<<get(m)<<' '<<sum[m]<<'\n';
	for(int m = 0;m < (1<<20);m++) sum[m] = sum[m] * (sum[m] - 1ll) / 2ll;
	//	for(int m = 0;m < (1<<20);m++) cerr<<get(m)<<' '<<sum[m]<<'\n';
	for(int i = 0;i < 20;i++) {
		for(int m = 0;m < (1<<20);m++) {
			if(m&(1<<i))
				sum[m] -= sum[m^(1<<i)];
		}
	}
	//	for(int m = 0;m < (1<<20);m++) cerr<<get(m)<<' '<<sum[m]<<'\n';
	for(int i = 0;i < 20;i++) {
		for(int m = 0;m < (1<<20);m++) {
			if(m&(1<<i))
				sum[m^(1<<i)] += sum[m];
		}
	}
	//	for(int m = 0;m < (1<<20);m++) cerr<<get(m)<<' '<<sum[m]<<'\n';
	for(int i = 0;i < Q;i++) {
		cin>>s;
		cout<<sum[get(s)]<<'\n';
	}
	return 0;
}
