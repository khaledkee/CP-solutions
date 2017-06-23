// Problem link: https://www.codechef.com/COOK83/problems/KNICOV/
/*
 * Idea:
 * DP[second previous column][previous column][current column][next column][current row index]
 * Find a way to fill the second previous column (as any row after the curent won't have any effect on it) and send the new state.
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

int N,M;
int dp[(1<<3)][(1<<3)][(1<<3)][(1<<3)][55];
int vis[(1<<3)][(1<<3)][(1<<3)][(1<<3)][55];
int visID;
bool can[(1<<3)][(1<<3)][(1<<3)][(1<<3)][55];
const int inf = 155;

void bt(int stp2,int stp1,int stc,int stn,int idx) {
  if(idx == M) {
     vis[stp2][stp1][stc][stn][idx] = visID;
     can[stp2][stp1][stc][stn][idx] = stp2 == (1<<N) - 1 && stp1 == (1<<N) - 1;
     dp[stp2][stp1][stc][stn][idx] = (can[stp2][stp1][stc][stn][idx]?0:inf);
     return;
  }
  if(vis[stp2][stp1][stc][stn][idx] == visID) return;
  vis[stp2][stp1][stc][stn][idx] = visID;
  can[stp2][stp1][stc][stn][idx] = false;
  dp[stp2][stp1][stc][stn][idx] = inf;
  for(int i = 0;i < (1<<N);i++) {
     int pre2msk = stp2;
     int pre1msk = stp1;
     int curmsk = stc;
     int nxt1msk = stn;
     int nxt2msk = 0;
     int num = 0;
     for(int j = 0;j < N;j++) {
        if(!(i&(1<<j))) continue;
        curmsk |= (1<<j);
        num++;
        if(j) pre2msk |= (1<<(j-1)),nxt2msk |= (1<<(j-1));
        if(j+1 < N) pre2msk |= (1<<(j+1)),nxt2msk |= (1<<(j+1));
        if(j > 1) pre1msk |= (1<<(j-2)),nxt1msk |= (1<<(j-2));
        if(j+2 < N) pre1msk |= (1<<(j+2)),nxt1msk |= (1<<(j+2));
     }
     if(pre2msk != (1<<N) - 1) continue;
     bt(pre1msk,curmsk,nxt1msk,nxt2msk,idx+1);
     if(can[pre1msk][curmsk][nxt1msk][nxt2msk][idx+1]) {
        can[stp2][stp1][stc][stn][idx] = true;
        assert(dp[pre1msk][curmsk][nxt1msk][nxt2msk][idx+1] < inf);
        dp[stp2][stp1][stc][stn][idx] = min(dp[stp2][stp1][stc][stn][idx],dp[pre1msk][curmsk][nxt1msk][nxt2msk][idx+1] + num);
     }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin>>T;
  while(T--) {
     cin>>N>>M;
     if(N == 1) {
        cout<<M<<'\n';
        continue;
     }
     visID++;
     bt((1<<N)-1,(1<<N)-1,0,0,0);
     assert(can[(1<<N)-1][(1<<N)-1][0][0][0]);
     assert(dp[(1<<N)-1][(1<<N)-1][0][0][0] < inf);
     cout<<dp[(1<<N)-1][(1<<N)-1][0][0][0]<<'\n';
  }
  return 0;
}
