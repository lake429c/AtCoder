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
  vector<lint> dam(n);
  REP(i,n) cin >> dam[i];

  //まず最も水の少ないダムを探す
  lint min = INT_MAX, min_ele = -1;
  REP(i,n-1){
    if(min > dam[i]){
      min = dam[i];
      min_ele = i;
    }
    if(min == 0) break;
  }

  vector<lint> rain(n,0);
  //水量最小のダムの水の分け方をすべて試していく
  REP(i,dam[min_ele]+1){
    vector<lint> tmp_dam(n,0);
    tmp_dam[min_ele] = dam[min_ele];
    if(min_ele != 0) tmp_dam[min_ele-1] += i;
    else tmp_dam[n-1] += i;
    rain[min_ele] = i * 2;
    tmp_dam[min_ele+1] += dam[min_ele] - i;
    rain[min_ele+1] = (dam[min_ele] - i) * 2;
    //水量最小のダムから時計回りに見ていく
    FOR(j,min_ele+1,n-1){
      tmp_dam[j+1] += dam[j] - tmp_dam[j];
      rain[j+1] = (dam[j] - tmp_dam[j]) * 2;
      tmp_dam[j] += dam[j] - tmp_dam[j];
    }
    //反時計回り
    IFOR(j,0,min_ele-1){
      if(j != 0) tmp_dam[j-1] += dam[j] - tmp_dam[j];
      else tmp_dam[n-1] += dam[j] - tmp_dam[j];
      rain[j] = (dam[j] - tmp_dam[j]) * 2;
      tmp_dam[j] += dam[j] - tmp_dam[j];
    }
    if(tmp_dam[n-1] == dam[n-1]) break;
  }

  REP(i,n) cout << rain[i] << " ";
  cout << endl;
  return 0;
}
