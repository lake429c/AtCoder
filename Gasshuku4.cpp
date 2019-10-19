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
  int h, w;
  lint d;
  cin >> h >> w >> d;
  std::vector<std::vector<lint>> a(h,std::vector<lint>(w));
  std::vector<plint> search_num(h*w);
  REP(i,h) REP(j,w){
    cin >> a[i][j];
    search_num[a[i][j]-1].first = i;
    search_num[a[i][j]-1].second = j;
  }
  lint q;
  cin >> q;
  std::vector<plint> koma(q);
  REP(i,q) cin >> koma[i].first >> koma[i].second;  //L,R

  std::vector<lint> mp_sum(h*w, -1);
  REP(tr,q){
    //駒を探す
    lint x, y;
    lint my_num = koma[tr].first;
    x = search_num[koma[tr].first-1].first;
    y = search_num[koma[tr].first-1].second;
    lint mp_sum = 0;
    while(1){
      //終了条件
      if(mp_sum[koma[tr].second] != -1){
        cout << mp_sum[koma[tr].second] << endl;
        break;
      }
      //駒の移動
      lint i, j;
      i = search_num[my_num+d-1].first;
      j = search_num[my_num+d-1].second;
      mp_sum[my_num] = abs(x-i)+abs(y-j);
      x = i;
      y = j;
      my_num += d;
    }
  }
  return 0;
}
