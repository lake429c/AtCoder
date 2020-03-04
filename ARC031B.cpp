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

int an_island(std::vector<string> _island, std::vector<int> _start, std::vector<std::vector<bool>>& _reach){
  if(_reach[_start[0]][_start[1]] && _island[_start[0]][_start[1]] == 'o'){
    _reach[_start[0]][_start[1]] = false;
    int tmp = 1;
    if(_start[0] != 0){
      tmp += an_island(_island,{_start[0]-1,_start[1]},_reach);
    }
    if(_start[0] != 9){
      tmp += an_island(_island,{_start[0]+1,_start[1]},_reach);
    }
    if(_start[1] != 0){
      tmp += an_island(_island,{_start[0],_start[1]-1},_reach);
    }
    if(_start[1] != 9){
      tmp += an_island(_island,{_start[0],_start[1]+1},_reach);
    }
    return tmp;
  }
  return 0;
}

int main()
{
  std::vector<string> island(10);
  REP(i,10) cin >> island[i];

  // 陸地のカウントと埋め立てる海の候補の検索
  int land_cnt = 0;
  std::vector<std::vector<int>> sea;
  std::vector<int> start;
  REP(i,10){
    REP(j,10){
      if(island[i][j] == 'o'){
        land_cnt++;
        if(start.size() == 0){
          start.push_back(i);
          start.push_back(j);
        }
      }else{
        int tmp = 0;
        if(i != 0 && island[i-1][j] == 'o') tmp++;
        if(i != 9 && island[i+1][j] == 'o') tmp++;
        if(j != 0 && island[i][j-1] == 'o') tmp++;
        if(j != 9 && island[i][j+1] == 'o') tmp++;
        if(tmp > 1) sea.push_back({i,j});
      }
    }
  }

  // もとから一つの島だった場合
  string ans = "NO";
  std::vector<std::vector<bool>> reach(10,std::vector<bool>(10,true));
  if(an_island(island,start,reach) == land_cnt) ans = "YES";
  // 一マス埋め立てて一つの島になる場合
  REP(i,sea.size()){
    island[sea[i][0]][sea[i][1]] = 'o';
    reach = std::vector<std::vector<bool>>(10,std::vector<bool>(10,true));
    if(an_island(island,start,reach) == land_cnt+1){
      ans = "YES";
      break;
    }
    island[sea[i][0]][sea[i][1]] = 'x';
  }

  cout << ans << "\n";
  return 0;
}
