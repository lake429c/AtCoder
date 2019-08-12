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
  std::vector<string> s(n);
  REP(i,n) cin >> s[i];

  std::vector<std::vector<int>> s_num(n,std::vector<int>(10));
  std::vector<int> tmp(10);
  lint cnt = 0;
  lint end = 1;
  REP(i,n){
    REP(j,10) tmp[j] = int(s[i][j]);
    sort(ALL(tmp));
    REP(j,end){
      if(equal(s_num[j].begin(), s_num[j].end(), tmp.begin(), tmp.end())){
        cnt += 1;
        break;
      }else if(j == end-1){
        REP(k,10) s_num[end-1][k] = tmp[k];
        end += 1;
        break;
      }
    }
  }

  cout << cnt << endl;
  return 0;
}
