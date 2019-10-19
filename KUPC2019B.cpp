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

int main()
{
  lint n, m, w;
  cin >> n >> m >> w;
  std::vector<plint> cost(n);
  REP(i, n) {
    cin >> cost[i].first >> cost[i].second;
  }
  std::vector<pint> limit(m);
  REP(i, m){
    cin >> limit[i].first >> limit[i].second;
  }

  std::vector<std::vector<lint>> dp(n+1, std::vector<lint>(w+1, 0));
  if(m != 0){
    std::vector<std::vector<int>> group(m);
    REP(i, m){
      bool notfind = true;
      REP(j, group.size()){
        if(find(group[j].begin(), group[j].end(), limit[i].first) != group[j].end()){
          group[j].push_back(limit[i].second);
          notfind = false;
          break;
        } else if(find(group[j].begin(), group[j].end(), limit[i].second) != group[j].end()){
          group[j].push_back(limit[i].first);
          notfind = false;
          break;
        }
      }
      if(notfind == true){
        group[i] = std::vector<int>{limit[i].first, limit[i].second};
      }
    }
    std::vector<plint> cost_cp = cost;

    for(std::vector<int> tmp: group){
      REP(i, tmp.size()){
        cost_cp[tmp[0]-1].first += cost[tmp[i]-1].first;
        cost_cp[tmp[0]-1].second += cost[tmp[i]-1].second;
        cost_cp[tmp[i]-1].first -= cost[tmp[i]-1].first;
        cost_cp[tmp[i]-1].second -= cost[tmp[i]-1].second;
      }
    }

    IREP(i, n) {
      REP(j, w+1) {
        if (j < cost_cp[i].first)
          dp[i][j] = dp[i + 1][j];
        else
          dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - cost_cp[i].first] + cost_cp[i].second);
      }
    }
  }else{
    IREP(i, n) {
      REP(j, w+1) {
        if (j < cost[i].first)
          dp[i][j] = dp[i + 1][j];
        else
          dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - cost[i].first] + cost[i].second);
      }
    }
  }
  cout << dp[0][w] << endl;
  return 0;
}
