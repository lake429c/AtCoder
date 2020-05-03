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

vector<vector<int>> suretsu;



int main()
{
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<lint>> a(q, vector<lint>(4));
  REP(i,q) cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];

  vector<int> res(n+1, m);
  res[0] = 0;
  lint max = 0;
  while(res[1] != 0){
    //処理
    //REP(i,n+1) cout << res[i];
    //cout << "\n";
    lint cnt = 0;
    REP(i,q){
      if(res[a[i][1]]-res[a[i][0]] == a[i][2]) cnt += a[i][3];
    }
    if(cnt > max) max = cnt;
    //数列のカウントダウン
    IFOR(i,1,n+1){
      if(res[i-1] < res[i]){
        res[i]--;
        FOR(j,i+1,n+1) res[j] = m;
        break;
      }
    }
  }

  cout << max << "\n";
  return 0;
}
