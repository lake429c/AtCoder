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
  vector<lint> a(n);
  REP(i,n) cin >> a[i];

  //山iに降った雨の量（偶数）＝ダムiとダムi-1に等量ずつ注ぐ
  vector<lint> rain(n,0);

  //まず最も水の少ないダムを探す
  lint min = INT_MAX, min_ele = -1;
  REP(i,n){
    if(min > a[i]){
      min = a[i];
      min_ele = i;
    }
    if(min == 0) break;
  }
  REP(i,min+1){
    vector<lint> tmp(n,0);
    tmp[min_ele] = a[min_ele];
    tmp[min_ele] -= i;
    if(min_ele != n){
      tmp[min_ele+1] = a[min_ele+1];
      tmp[min_ele+1] -= i;
      rain[min_ele+1] = i*2;
      FOR(j,min_ele+1,n){
        //tmp[j] -= tmp[j];
        tmp[j+1] = a[j+1];
        tmp[j+1] -= tmp[j];
        if(tmp[j+1] < 0) break;
        rain[j+1] = tmp[j]*2;
      }
    }
    IFOR(j,1,min_ele){
      tmp[j] = a[j];
      tmp[j] -= tmp[j+1];
      if(tmp[j+1] < 0) break;
      rain[j+1] = tmp[j+1];
    }
    rain[1] = tmp[1]*2;
    if(tmp[1] == tmp[n] && rain[1]/2 == tmp[n]) break;
  }

  REP(i,n) cout << rain[i] << " ";
  cout << endl;
  return 0;
}
