#include<bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
using pqueg = priority_queue<int, vector<int>, greater<int>>;
using pquel = priority_queue<int, vector<int>, less<int>>;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
int lcm(int a, int b){
  return a / __gcd(a, b) * b;
}
int r_int(int a, int b){
  return rand() % b + a;
}
const lint mod=1e9+7;



int main()
{
  lint n, k;
  cin >> n >> k;
  vector<lint> a(n);
  lint plus = 0, minus = 0, zeros = 0;
  REP(i,n){
    cin >> a[i];
    if(a[i] > 0) plus++;
    else if(a[i] < 0) minus++;
    else zeros++;
  }

  sort(ALL(a));
  lint res;
  vector<lint> multi;
  if(plus*minus >= k){
    lint l = 1, u = 1;
    while((l+1)*u < k && l*(u+1) < k){
      if(abs(a[l]) > abs(a[n-u-1])) l++;
      else u++;
    }
    res = a[l-1]*a[n-u];
  }else if(zeros*(plus+minus) >= k){
    res = 0;
  }else{

  }

  cout << res << "\n";
  return 0;
}
