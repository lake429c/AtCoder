#include<bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
const lint mod=1e9+7;

int main()
{
  int n, x, y;
  cin >> n >> x >> y;


  vector<vector<int>> res(n, vector<int>(n,-1));
  vector<vector<int>> que;
  REP(i,n-1){
    res[i][i] = 0;
    res[i][i+1] = 1;
    que.push_back({i,i+1});
  }
  res[n-1][n-1] = 0;
  res[x-1][y-1] = 1;
  que.push_back({x-1,y-1});
  res[y-1][x-1] = 1;
  que.push_back({y-1,x-1});

  while(que.size() != 0){
    if(que[0][0]+1 != n && res[que[0][0]+1][que[0][1]] == -1){
      res[que[0][0]+1][que[0][1]] = res[que[0][0]][que[0][1]] + 1;
      que.push_back({que[0][0]+1,que[0][1]});
    }
    if(que[0][0]-1 != -1 && res[que[0][0]-1][que[0][1]] == -1){
      res[que[0][0]-1][que[0][1]] = res[que[0][0]][que[0][1]] + 1;
      que.push_back({que[0][0]-1,que[0][1]});
    }
    if(que[0][1]+1 != n && res[que[0][0]][que[0][1]+1] == -1){
      res[que[0][0]][que[0][1]+1] = res[que[0][0]][que[0][1]] + 1;
      que.push_back({que[0][0],que[0][1]+1});
    }
    if(que[0][1]-1 != -1 && res[que[0][0]][que[0][1]-1] == -1){
      res[que[0][0]][que[0][1]-1] = res[que[0][0]][que[0][1]] + 1;
      que.push_back({que[0][0],que[0][1]-1});
    }
    que.erase(que.begin());
  }
  /*
  REP(i,n){
    REP(j,res[i].size()){
      cout << res[i][j] << " ";
    }
    cout << "\n";
  }*/

  vector<int> num(n-1,0);
  REP(i,n-1){
    FOR(j,i+1,n){
      num[res[i][j]-1]++;
    }
  }

  REP(i,n-1) cout << num[i] << "\n";
  return 0;
}
