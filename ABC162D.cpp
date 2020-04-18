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
  string s;
  cin >> s;

  lint cntR = 0, cntG = 0, cntB = 0;
  REP(i,n){
    if(s[i] == 'R') cntR++;
    if(s[i] == 'G') cntG++;
    if(s[i] == 'B') cntB++;
  }
  lint cnt = 0;
  REP(i,n){
    FOR(j,1,n){
      if(i+j*2 > n-1) break;
      if(s[i] != s[i+j] && s[i] != s[i+j*2] && s[i+j] != s[i+j*2]) cnt++;
    }
  }
  cout <<  cntR*cntG*cntB - cnt << "\n";
  return 0;
}
