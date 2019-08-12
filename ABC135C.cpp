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
  lint n;
  cin >> n;
  std::vector<lint> town(n+1);
  REP(i,n+1) cin >> town[i];
  std::vector<lint> hero(n);
  REP(i,n) cin >> hero[i];

  std::vector<lint> sum_mon(n);
  REP(i,n) sum_mon[i] = town[i] + town[i+1];
  std::vector<lint> good_sum_mon(n);
  REP(i,n) good_sum_mon[i] = sum_mon[i];
  sort(ALL(good_sum_mon));
  sort(ALL(hero));
  std::vector<lint> good_hero(n,-1);
  REP(i,n){
    REP(j,n){
      if(good_sum_mon[i] == sum_mon[j] && good_hero[j] == -1){
        good_hero[j] = hero[i];
      }
    }
  }

  return 0;
}
