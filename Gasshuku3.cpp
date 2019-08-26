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
  std::vector<lint> a(n);
  REP(i,n) cin >> a[i];

  lint now_x = 0;
  lint cost_sum = 0;
  std::vector<lint> cost_from_1(n);
  std::vector<lint> cost_from_n(n);
  REP(i,n){
    cost_sum += abs(a[i]-now_x);
    cost_from_1[i] = cost_sum;
    now_x = a[i];
  }
  cost_sum += abs(a[n-1]);
  cost_from_1[n-1] = cost_sum;

  now_x = 0;
  cost_sum = 0;
  IREP(i,n){
    cost_sum += abs(a[i]-now_x);
    cost_from_n[i] = cost_sum;
    now_x = a[i];
  }
  cost_sum += abs(a[0]);
  cost_from_n[0] = cost_sum;

  REP(i,n){
    lint result = 0;
    if(i != 0 && i != n-1){
      result += cost_from_1[i-1];
      result += cost_from_n[i+1];
      result += abs(a[i-1]-a[i+1]);
    }else if(i == 0){
      result += cost_from_n[1];
      result += abs(a[1]);
    }else if(i == n-1){
      result += cost_from_1[n-2];
      result += abs(a[n-2]);
    }
    cout << result << endl;
  }
  return 0;
}
