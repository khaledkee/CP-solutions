// Problem link: https://www.codechef.com/COOK83/problems/ADADET/
/*
 * Idea:
 * Create a stack of upper hulls while iterating from right to left.
 * Insert new upper hull after encountering a tower lower than the one to its right.
 * Pop the upper hull after encountering a tower higher than the one in the upper hull before the current upper hull.
 * The result is the previous tower in the same upper hull of the current tower.
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

long long INF = 1e100;
long long EPS = 1e-12;

struct PT {
  long long x, y;
  PT() {}
  PT(long long x, long long y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (long long c)     const { return PT(x*c,   y*c  ); }
  bool operator<(const PT &p)  const { return make_pair(x,y)<make_pair(p.x,p.y); }
  bool operator==(const PT &p)  const { return !(*this < p) && !(p < *this); }
};
long long dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
long long dist2(PT p, PT q)   { return dot(p-q,p-q); }
long long cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
istream &operator>>(istream &is, PT &p) {return is >> p.x >> p.y; }
ostream &operator<<(ostream &os, const PT &p) {return os << "(" << p.x << "," << p.y << ")";}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin>>T;
  while(T--) {
     int N;
     cin>>N;
     vector<PT> v(N);
     for(int i = 0;i < N;i++) cin>>v[i];
     vector<vector<int> > upper;
     vector<int> res(N);
     upper.push_back({N-1});
     res[N-1] = -1;
     for(int i = N-2;i >= 0;i--) {
        while(upper.size() > 1) {
           if(v[upper[upper.size()-2].back()].y < v[i].y) {
              upper.pop_back();
           } else break;
        }
        while(upper.back().size() > 1 && cross(v[upper.back().back()] - v[upper.back()[upper.back().size()-2]], v[i] - v[upper.back()[upper.back().size()-2]]) <= 0 && v[i].y > v[upper.back().back()].y) {
           upper.back().pop_back();
        }
        if(v[upper.back().back()].y >= v[i].y) {
           res[i] = -1;
           upper.push_back({i});
        } else {
           res[i] = upper.back().back()+1;
           upper.back().push_back(i);
        }
     }
     for(int i = 0;i < N;i++) cout<<res[i]<<" \n"[i+1 == N];
  }
  return 0;
}
