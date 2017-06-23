// Problem link: http://acm.timus.ru/problem.aspx?num=1040
/*
 * Idea:
 * Create dummy node and connect it to all odd degree nodes in the graph
 * Make euler tour of the new graph and assign consective ids for consective (real) edges
 * This enssures that for nodes with degree more than 1, at least two edges will have GCD of 1
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

const int mxN = 53;
vector<pair<int,int> > g[mxN];
int stg[mxN];
int res[mxN * mxN];
int deg[mxN];

int N,M;
int k;
void dfs(int v,int par) {
	while(stg[v] < (int)g[v].size()) {
		auto p = g[v][stg[v]];
		int u = p.first;
		int e = p.second;
		if(u == par || deg[u] == 0 || res[e]) {
			stg[v]++;
			continue;
		}
		if(e < M)
			res[e] = ++k;
		else
			res[e] = 1;
		deg[v]--,deg[u]--;
		stg[v]++;
		dfs(u,v);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int u,v;
	cin>>N>>M;
	for(int i = 0;i < M;i++) {
		cin>>u>>v;
		u--,v--;
		g[u].push_back({v,i});
		g[v].push_back({u,i});
		deg[u]++,deg[v]++;
	}
	int cur = M;
	for(int i = 0;i < N;i++)
		if(deg[i]&1)
			g[N].push_back({i,cur}),g[i].push_back({N,cur}),deg[i]++,deg[N]++,cur++;
	for(int i = 0;i < N;i++) {
		while(deg[i]) {
			dfs(i,-1);
		}
	}
	cout<<"YES\n";
	for(int i = 0;i < M;i++) cout<<res[i]<<" \n"[i+1 == M];
	return 0;
}
