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
  lint l, r;
  cin >> l >> r;

  lint min = INT_MAX;
  if(r-l>=2019){
    //2019個にいっこかならず2019の倍数が存在する
    min = 0;
  }else{
    FOR(i,l,r){
      FOR(j,i+1,r+1){
        lint tmp = ((i%2019)*(j%2019))%2019;
        if(tmp < min) min = tmp;
      }
    }
  }

  cout << min << endl;
  return 0;
}
