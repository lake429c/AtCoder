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

int K;
std::vector<std::vector<std::vector<int>>> memo;

int gcd(int a, int b, int c){

  if(memo[a-1][b-1][c-1] != -1) return memo[a-1][b-1][c-1];
  if(memo[b-1][c-1][a-1] != -1) return memo[b-1][c-1][a-1];
  if(memo[c-1][a-1][b-1] != -1) return memo[c-1][a-1][b-1];
  if(memo[a-1][c-1][b-1] != -1) return memo[a-1][c-1][b-1];
  if(memo[b-1][a-1][c-1] != -1) return memo[b-1][a-1][c-1];
  if(memo[c-1][b-1][a-1] != -1) return memo[c-1][b-1][a-1];
  int res = 1;
  REP(i,K){
    if(i+1 > a || i+1 > b || i+1 > c) break;
    if(a%(i+1) == 0 && b%(i+1) == 0 && c%(i+1) == 0){
      res = i+1;
    }
  }
  memo[a-1][b-1][c-1] = res;
  //cout << res << "\n";
  return res;
}

int main()
{
  cin >> K;
  memo = std::vector<std::vector<std::vector<int>>>(K,std::vector<std::vector<int>>(K,std::vector<int>(K,-1)));
  lint cnt = 0;
  REP(i,K){
    REP(j,K){
      REP(s,K){
        cnt += gcd(i+1,j+1,s+1);
      }
    }
  }
  cout << cnt << "\n";
  return 0;
}
