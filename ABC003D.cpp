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

#define MOD 1000000007
lint ncr(int n, int r){
  lint result=1;
  int div = 1;
  FOR(i, r+1, n+1){
    result *= i;
    if(div < n-r+1 && result%div == 0){
      result /= div;
      div++;
    }
    result = result % MOD;
  }
  return result;
}

int main()
{
  //社員室の広さ（RxC）
  int r, c;
  cin >> r >> c;
  //区切りの広さ（XxY）
  int x, y;
  cin >> x >> y;
  //デスクとラックの数
  int d, l;
  cin >> d >> l;

  lint result=ncr(x*y,d);
  result = (result*(r-x+1))%MOD;
  result = (result*(c-y+1))%MOD;
  cout << result << endl;
  return 0;
}
