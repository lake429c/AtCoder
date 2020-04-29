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

double ave(int x){
  return (double)(1+x)/2;
}

int main()
{
  lint n, k;
  cin >> n >> k;
  vector<int> p(n);
  REP(i,n) cin >> p[i];

  vector<double> memo(n);
  double max = 0;
  REP(i,n){
    memo[i] = ave(p[i]);
    if(i != 0) memo[i] += memo[i-1];
  }
  REP(i,n-k){
    if(memo[i+k]-memo[i] > max) max = memo[i+k]-memo[i];
  }

  //cout << max << "\n";
  printf("%.10lf",max);
  return 0;
}
