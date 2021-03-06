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
  std::vector<std::vector<int>> a(3,std::vector<int>(3));
  REP(i,3) cin >> a[i][0] >> a[i][1] >> a[i][2];
  int n;
  cin >> n;
  std::vector<int> b(n);
  REP(i,n) cin >> b[i];

  std::vector<std::vector<int>> res(3,std::vector<int>(3,0));
  REP(i,n){
    REP(j,3){
      REP(k,3){
        if(a[j][k] == b[i]) res[j][k] = 1;
      }
    }
  }

  bool flg = false;
  REP(i,3){
    if(res[i][0] == 1 && res[i][1] == 1 && res[i][2] == 1) flg = true;
    if(res[0][i] == 1 && res[1][i] == 1 && res[2][i] == 1) flg = true;
  }
  if(res[0][0] == 1 && res[1][1] == 1 && res[2][2] == 1) flg = true;
  if(res[0][2] == 1 && res[1][1] == 1 && res[2][0] == 1) flg = true;

  if(flg) cout << "Yes\n";
  else cout << "No\n";
  return 0;
}
