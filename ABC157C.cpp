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
  int n, m;
  cin >> n >> m;
  std::vector<int> s(m);
  std::vector<int> c(m);
  REP(i,m) cin >> s[i] >> c[i];

  std::vector<int> num(n,-1);
  REP(i,m){
    if(num[s[i]-1] == -1){
      num[s[i]-1] = c[i];
    }else if(num[s[i]-1] != c[i]){
      cout << -1 << "\n";
      return 0;
    }
  }

  REP(i,n){
    if(n != 1 && num[0] == 0){
      cout << -1 << "\n";
      return 0;
    }
    if(i != 0 && num[i] == -1){
      num[i] = 0;
    }else if(i == 0 && num[i] == -1 && n != 1){
      num[i] = 1;
    }else if(i == 0 && num[i] == -1 && n == 1){
      num[i] = 0;
    }
  }

  REP(i,n) cout << num[i];
  cout << "\n";
  return 0;
}
