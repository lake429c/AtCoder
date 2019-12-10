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
  int n;
  cin >> n;
  std::vector<int> a(n);
  std::vector<std::vector<int>> x(n,std::vector<int>(n));
  std::vector<std::vector<int>> y(n,std::vector<int>(n));
  REP(i,n){
    cin >> a[i];
    REP(j,a[i]){
      cin >> x[i][j] >> y[i][j];
    }
  }

  std::vector<std::vector<int>> g(n,std::vector<int>(n,1));
  REP(i,n){
    REP(j,n){
      g[i][x[i][j]-1] = y[i][j];
    }
  }

  int cnt=0;
  bool allzero=true;
  REP(i,n-1){
    bool flg=true;
    for(int j=i+1;j<n;j++){
      if(g[i][j]!=g[j][i]) flg=false;
      if(g[i][j]!=0) allzero=false;
    }
    if(flg==true) cnt++;
  }
  if(allzero==true) cnt=1;

  cout << cnt << "\n";
  return 0;
}
