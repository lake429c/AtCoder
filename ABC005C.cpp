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
  // t秒以内のたこ焼きを売る
  int t;
  cin >> t;
  // n個のたこ焼きを売る
  int n;
  cin >> n;
  // a秒後にたこ焼きが焼きあがる
  std::vector<int> a(n);
  REP(i,n) cin >> a[i];
  // m人の客
  int m;
  cin >> m;
  // b秒後に客が来る
  std::vector<int> b(m);
  REP(i,m) cin >> b[i];

  int time = 0;
  int tako = 0, kyaku = 0;
  while(time++ < b[b.size()-1]){
    if(time - a[tako] > t) tako++;  // 腐ったたこ焼きを廃棄
    while(b[kyaku] == time){  // 客がいる限りたこ焼きを売る
      if(tako > n-1) break;  // 売り切れ
      if(a[tako] <= time){  // 焼けたたこ焼きがある
        tako++;
        kyaku++;
      }else{  // 焼けたたこ焼きがない
        break;
      }
    }
  }

  string res;
  if(kyaku == m) res = "yes";
  else res = "no";
  cout << res << "\n";

  return 0;
}
