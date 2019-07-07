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
  int n, d;
  cin >> n >> d;
  vector<vector<int>> x(n,vector<int>(d));
  REP(i,n) REP(j,d) cin >> x[i][j];

  int result = 0;
  REP(i,n){
    FOR(j,i+1,n){
      int tmp = 0;
      REP(k,d) tmp += pow(x[i][k] - x[j][k], 2);
      if(tmp == pow((int)sqrt(tmp),2)) result++;
    }
  }

  cout << result << endl;
  return 0;
}
