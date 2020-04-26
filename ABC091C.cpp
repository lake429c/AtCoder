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
  // 赤点の原点からの距離
  std::vector<pint> red(n);
  REP(i,n) cin >> red[i].first >> red[i].second;
  // 青点の原点からの距離
  std::vector<pint> blue(n);
  REP(i,n) cin >> blue[i].first >> blue[i].second;

  // 昇順ソート
  sort(red.begin(),red.end(),[](const pint &alpha,const pint &beta){return alpha.first < beta.first;});
  sort(blue.begin(),blue.end(),[](const pint &alpha,const pint &beta){return alpha.first < beta.first;});
  int cnt1 = 0, indR = 0, indB = 0;
  while(indB < blue.size()){
    if(red[indR].first < blue[indB].first && red[indR].second < blue[indB].second){
      cnt1++;
      indR++;
    }
    indB++;
  }
  // 昇順ソート
  sort(red.begin(),red.end(),[](const pint &alpha,const pint &beta){return alpha.second < beta.second;});
  sort(blue.begin(),blue.end(),[](const pint &alpha,const pint &beta){return alpha.second < beta.second;});
  int cnt2 = 0;
  indR = 0, indB = 0;
  while(indB < blue.size()){
    if(red[indR].first < blue[indB].first && red[indR].second < blue[indB].second){
      cnt2++;
      indR++;
    }
    indB++;
  }

  if(cnt1 > cnt2) cout << cnt1 << "\n";
  else cout << cnt2 << "\n";
  return 0;
}
