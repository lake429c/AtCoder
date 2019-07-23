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

  lint max=0, maxe=-1;
  REP(i,n) if(a[i]>max){
    max = a[i];
    maxe = i;
  }

  sort(a.begin(),a.end());
  REP(i,n){
    if(i != maxe) cout << a[n-1] << endl;
    else cout << a[n-2] << endl;
  }
  return 0;
}
