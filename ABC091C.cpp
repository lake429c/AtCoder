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
  std::vector<pint> red(n);
  REP(i,n) cin >> red[i].first >> red[i].second;
  std::vector<pint> blue(n);
  REP(i,n) cin >> blue[i].first >> blue[i].second;

  // y座標で降順ソート
  sort(red.begin(),red.end(),[](const pint &alpha,const pint &beta){return alpha.second > beta.second;});
  // x座標で昇順ソート
  sort(blue.begin(),blue.end(),[](const pint &alpha,const pint &beta){return alpha.first < beta.first;});
  lint cnt = 0;
  REP(i,n){
    REP(j,red.size()){
      // 青点よりx,y座標が小さい赤点の中でy座標最大の物を選ぶ
      if(red[j].first < blue[i].first && red[j].second < blue[i].second){
        red.erase(red.begin()+j);
        cnt++;
        break;
      }
    }
  }

  cout << cnt << "\n";
  return 0;
}
