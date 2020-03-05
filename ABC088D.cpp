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

void bfs(std::vector<string> _map, std::vector<std::vector<int>>& _dist, std::vector<std::vector<int>>& _que){
  int h = _map.size(), w = _map[0].size();
  int min = 1000;
  if(_que[0][0] != 0 && _map[_que[0][0]-1][_que[0][1]] == '.'){
    if(_dist[_que[0][0]-1][_que[0][1]] == -1){
      _que.push_back({_que[0][0]-1,_que[0][1]});
    }else if(_dist[_que[0][0]-1][_que[0][1]] < min){
      min = _dist[_que[0][0]-1][_que[0][1]];
    }
  }
  if(_que[0][0] != h-1 && _map[_que[0][0]+1][_que[0][1]] == '.'){
    if(_dist[_que[0][0]+1][_que[0][1]] == -1){
      _que.push_back({_que[0][0]+1,_que[0][1]});
    }else if(_dist[_que[0][0]+1][_que[0][1]] < min){
      min = _dist[_que[0][0]+1][_que[0][1]];
    }
  }
  if(_que[0][1] != 0 && _map[_que[0][0]][_que[0][1]-1] == '.'){
    if(_dist[_que[0][0]][_que[0][1]-1] == -1){
      _que.push_back({_que[0][0],_que[0][1]-1});
    }else if(_dist[_que[0][0]][_que[0][1]-1] < min){
      min = _dist[_que[0][0]][_que[0][1]-1];
    }
  }
  if(_que[0][1] != w-1 && _map[_que[0][0]][_que[0][1]+1] == '.'){
    if(_dist[_que[0][0]][_que[0][1]+1] == -1){
      _que.push_back({_que[0][0],_que[0][1]+1});
    }else if(_dist[_que[0][0]][_que[0][1]+1] < min){
      min = _dist[_que[0][0]][_que[0][1]+1];
    }
  }
  if(_que[0][0] == 0 && _que[0][1] == 0) min = -1;
  _dist[_que[0][0]][_que[0][1]] = min+1;
  _que.erase(_que.begin());
  return;
}

int main()
{
  int h, w;
  cin >> h >> w;
  std::vector<string> map(h);
  REP(i,h) cin >> map[i];

  std::vector<std::vector<int>> dist(h,std::vector<int>(w,-1));
  std::vector<std::vector<int>> que(1,std::vector<int>(2,0));

  while(que.size() != 0){
    bfs(map,dist,que);
  }

  int goal = dist[h-1][w-1];
  if(goal == -1){
    cout << -1 << "\n";
    return 0;
  }

  int score = 0;
  /*
  std::vector<bool> check(goal+1,true);
  REP(i,h){
    REP(j,w){
      if(map[i][j] == '.'){
        if(dist[i][j] >= 0 && dist[i][j] <= goal && check[dist[i][j]]){
          check[dist[i][j]] = false;
        }else{
          score++;
        }
      }
    }
  }
  */
  REP(i,h) REP(j,w) if(map[i][j] == '.') score++;

  cout << score-goal-1 << "\n";
  return 0;
}
