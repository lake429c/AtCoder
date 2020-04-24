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
  lint n, k;
  cin >> n >> k;

  // ありうる和の数
  lint cnt = 0;
  // k個の数を足したときの最も大きい数
  lint sum_up = 0;
  IFOR(i,n+1-k,n+1){
    sum_up += i;
    sum_up %= mod;
  }
  // k個の数を足したときの最も小さい数
  lint sum_low = 0;
  FOR(i,0,k){
    sum_low += i;
    sum_low %= mod;
  }
  cnt += sum_up-sum_low+1;
  // kをだんだん大きくしていく
  while(k != n+1){
    k++;
    sum_up += n+1-k;
    sum_up %= mod;
    sum_low += k-1;
    sum_low %= mod;
    cnt += sum_up-sum_low+1;
  }
  cout << (cnt+1)%mod << "\n";
  return 0;
}
