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
  int n;
  cin >> n;
  std::vector<int> a(n);
  REP(i,n) cin >> a[i];
  std::vector<int> b(n);
  REP(i,n) cin >> b[i];
  std::vector<int> c(n-1);
  REP(i,n-1) cin >> c[i];

  lint happiness = 0;
  REP(i,n){
    happiness += b[a[i]-1];
    if(i!=n-1 && a[i+1]-a[i] == 1){
      happiness += c[a[i]-1];
    }
  }

  cout << happiness << endl;

  return 0;
}
