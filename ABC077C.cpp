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
  vector<lint> a(n);
  REP(i,n) cin >> a[i];
  vector<lint> b(n);
  REP(i,n) cin >> b[i];
  vector<lint> c(n);
  REP(i,n) cin >> c[i];

  // 二分探索のために昇順ソート
  sort(ALL(a));
  sort(ALL(b));
  sort(ALL(c));
  // 高速化のためにメモを作る
  vector<lint> b_memo(n, 0);
  auto itr1 = upper_bound(ALL(b), a[0]);
  IFOR(j,distance(b.begin(), itr1),b.size()){
    auto itr2 = upper_bound(ALL(c), b[j]);
    b_memo[j] = distance(itr2, c.end());
    if(j != b.size()-1) b_memo[j] += b_memo[j+1];
  }
  // 数える
  lint cnt = 0;
  REP(i,n){
    auto itr = upper_bound(ALL(b), a[i]);
    if(itr1 != b.end()) cnt += b_memo[distance(b.begin(), itr)];
  }

  cout << cnt << "\n";
  return 0;
}
