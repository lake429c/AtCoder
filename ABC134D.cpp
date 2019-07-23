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
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<int> b(n,0);
  IFOR(i,n/2,n) b[i] = a[i];
  IFOR(i,0,n/2){
    lint cnt = 0;
    IFOR(j,i+1,n) if(j%i == 0) cnt += b[j];
    if(cnt%2 != a[i]) b[i] = 1;
  }
  /*
  lint cnt = 0;
  REP(i,n) cnt += a[i];
  if(cnt%2 != a[0]) b[0] = 1;
  */
/*
  lint m = 0;
  IREP(i,n) if(b[i] != 0){
    m = i;
    break;
  }
  cout << m+1 << endl;
  */
  REP(i,3) cout << b[i] << endl;
  return 0;
}
